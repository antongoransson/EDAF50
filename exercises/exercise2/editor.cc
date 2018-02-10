#include "editor.h"
#include <string>
#include <iostream>

using std::string;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char type;
	char in = text[pos];
	string::size_type number_left = 0;
	switch (in) {
		case ']': type = '['; break;
		case '}': type = '{'; break;
		case ')': type = '('; break;
		default: return  string::npos; break;
	}
	for (string::size_type i = pos - 1; i > 0; --i) {
		if (text[i] == in)
			++number_left;
		else if (text[i] == type) {
			if (number_left == 0) return i;
			--number_left;
		}
	}
	return  string::npos;
}
