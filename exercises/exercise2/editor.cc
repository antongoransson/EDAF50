#include "editor.h"
#include <string>
#include <iostream>

using std::string;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char type;
	char in = text[pos];
	string::size_type number_right = 0, number_left = 0, total= 0;
	switch (in) {
		case ']': type = '['; break;
		case '}': type = '{'; break;
		case ')': type = '('; break;
		default: return -1; break;
	}
	for (string::size_type i = 0; i < text.length(); i++) {
		char c = text[i];
		if (c == type)
			total++;
		if (c == in && i <= pos)
			number_right++;
	}

	for (string::size_type i = 0; i < text.length(); i++) {
		if (text[i] == type)
			number_left++;
		if (total - number_right + 1 == number_left)
			return i;
	}

	return -1;
}
