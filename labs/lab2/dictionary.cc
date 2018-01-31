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
			 vector<string> trigrams((size));
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
	string::size_type i;
	add_trigram_suggestions(suggestions, word);
	// rank_suggestions(suggestions, word);
	// trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	string::size_type i, nbr_trigrams;
	if (word.length() < 3)
		return;
	else
		nbr_trigrams = word.length() - 2;
	vector<string> trigrams(nbr_trigrams);
	for(string::size_type i = 0; i < nbr_trigrams; i++)
			trigrams[i] = word.substr(i, 3);
	sort(trigrams.begin(), trigrams.end());
	for(i = word.length() - 1; i <= word.length() + 1; ++i ){
		for(auto w: words[i]) {
			if(w.get_matches(trigrams) >= nbr_trigrams / 2 )
				suggestions.push_back(w.get_word());
		}
	}
	return;
}
