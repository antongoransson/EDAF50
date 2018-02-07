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
	size_t count {0}, i {0}, j {0};
	while (i < t.size() && j < trigrams.size()) {
		if (t[i] == trigrams[j]) {
			++count;
			++j;
			++i;
		} else if(t[i] < trigrams[j]) ++i;
		else if(t[i]  > trigrams[j]) ++j;
	}

	while (i < t.size() && trigrams.size() != 0) {
		if (t[i] == trigrams[j -1]) ++count;
		++i;
	}

	while (j < trigrams.size() && t.size() != 0) {
		if (t[i- 1] == trigrams[j]) ++count;
		++j;
	}
	return count;
}
