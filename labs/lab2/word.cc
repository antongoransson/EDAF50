#include <string>
#include <vector>
#include "word.h"
#include <fstream>
#include <iostream>

using std::vector;
using std::string;
using std::cout;

Word::Word(const string& w, const vector<string>& t): word(w), trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int count = 0;
	for(auto& c: t) {
		for(auto& wt: trigrams) {
			if (c.compare(wt) == 0) {
				++count;
				break;
			} else if (c.compare(wt) < 0)
				break;
		}
	}
	return count;
}
