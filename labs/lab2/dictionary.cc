#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <sstream>

using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::endl;
using std::stringstream;
using std::min;

Dictionary::Dictionary() {
	string line, trigram, word;
	string::size_type i = 0, size = 0;
	ifstream input ("words.txt");
	 if (input.is_open()) {
		 while (getline (input, line)) {
			 i = 0;
			 stringstream ss(line);
			 ss >> word;
			 dict.insert(word);
			 ss >> size;
			 vector<string> trigrams(size);
			 while(ss >> trigram) {
				 trigrams[i] = trigram;
				 ++i;
			 }
			 words[word.length()].push_back(Word(word, trigrams));
		 }
		 input.close();
	 }
 else cout << "Unable to open file";
}

bool Dictionary::contains(const string& word) const {
	const auto got = dict.find (word);
	return got != dict.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	string::size_type i, nbr_trigrams, length = word.length();
	if (length < 3)
		return;
	else
		nbr_trigrams = length - 2;
	vector<string> trigrams(nbr_trigrams);

	// Create trigrams for word
	for(string::size_type i = 0; i < nbr_trigrams; i++)
			trigrams[i] = word.substr(i, 3);
	sort(trigrams.begin(), trigrams.end());

	// Loop through words on word.length +- 1
	for(i = length - 1; i <= length + 1; ++i ){
		for(auto w: words[i]) {
			if(w.get_matches(trigrams) >= nbr_trigrams / 2 )
				suggestions.push_back(w.get_word());
		}
	}
	return;
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	string::size_type i, j, word_len = word.length();
	vector<string> suggestion_ranks[10];
	for(auto s: suggestions) {
		string::size_type s_len = s.length();
		int d[26][26];
		d[0][0] = 0;
		//d ( i, 0 ) = i
		for (i = 1; i <= word_len; ++i)
			d[i][0] = i;
		//d (0, j ) = j
		for (j = 1; j <= s_len; ++j)
			d[0][j] = j;
		for (i = 1; i <= word_len; ++i) {
			for (j = 1; j <= s_len; ++j) {
				d[i][j] = min({ word[i- 1] == s[j - 1] ? d[i - 1][j - 1] : d[i - 1][j - 1] + 1, d[i - 1][j] + 1,
					d[i][j - 1] + 1 });
			}
		}
		suggestion_ranks[d[word_len][s_len]].push_back(s);
	}
	j = 0;
	for(i = 0; i < 10; ++i) {
		sort(suggestion_ranks[i].begin(), suggestion_ranks[i].end());
		for(auto& w: suggestion_ranks[i]) {
			suggestions[j] = w;
			j++;
		}
	}
}
void Dictionary::trim_suggestions(vector<std::string>& suggestions) const{
	suggestions = vector<string>(suggestions.begin(), suggestions.begin() + 5);
}
