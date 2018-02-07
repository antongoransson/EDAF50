#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "word.h"
#include "dictionary.h"

using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;
using std::pair;
using std::make_pair;
using string_st = string::size_type;

Dictionary::Dictionary() {
	string line, trigram, word;
	ifstream input ("words.txt");
	 if (input.is_open()) {
		 while (getline (input, line)) {
			 stringstream ss(line);
			 ss >> word;
			 dict.insert(word);
			 ss >> trigram;
			 vector<string> trigrams;
			 while (ss >> trigram)
				 trigrams.push_back(trigram);
			 words[word.length()].push_back(Word(word, trigrams));
		 }
		 input.close();
	 }
 else cout << "Unable to open file";
}

bool Dictionary::contains(const string& word) const {
	return dict.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string word) const {
	string_st len {word.length()};
	if (len < 3)
		return;
	string_st nbr_trigrams {len - 2};
	vector<string> trigrams(nbr_trigrams);

	// Create trigrams for word
	for (string_st i = 0; i < nbr_trigrams; i++)
			trigrams[i] = word.substr(i, 3);
	sort(trigrams.begin(), trigrams.end());

	// Loop through words on word.length +- 1
	for (string_st i = len - 1; i <= len + 1 && i <= WORD_SIZE; ++i) {
		for (const auto w: words[i]) {
			if (w.get_matches(trigrams) >= nbr_trigrams / 2)
				suggestions.push_back(w.get_word());
		}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string word) const {
	if (word.length() < 3)
		return;

	vector<pair<int, string>> distances;
	for(const auto& s: suggestions) {
		unsigned int cost = levenshteinDistance(word, s);
		distances.push_back(make_pair(cost, s));
	}
	sort(distances.begin(), distances.end());
	suggestions.clear();
	for (auto s: distances) {
		suggestions.push_back(s.second);
	}
}

unsigned int Dictionary::levenshteinDistance(const string word, const string s) const {
	string::size_type s_len {s.length()}, w_len {word.length()};
	int d[26][26];
	d[0][0] = 0;
	for (string_st i = 1; i <= w_len; ++i) d[i][0] = i;
	for (string_st j = 1; j <= s_len; ++j) d[0][j] = j;
	// Calculate cost using Levenshtein distance
	for (string_st i = 1; i <= w_len; ++i)
		for (string_st j = 1; j <= s_len; ++j)
			d[i][j] = min({ d[i-1][j-1] + (word[i-1] == s[j-1] ? 0 : 1), d[i-1][j] + 1,	d[i][j-1] + 1 });
	return d[w_len][s_len];
}

void Dictionary::trim_suggestions(vector<std::string>& suggestions) const {
	size_t size = suggestions.size() >= 5 ? 5 : suggestions.size();
	suggestions.resize(size);
}
