#include "editor.h"

#include <string>
#include <iostream>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char type = '.';
	char in = text[pos];
	string::size_type number = 0, index = 0, number2 = 0, index2 = 0, len= 0, total= 0;
	switch (in) {
		case ']': type = '['; break;
		case '}': type = '{'; break;
		case ')': type = '('; break;
		default: return len -1; break;
	}
	for (const char& c: text) {
		if (c == type)
			total++;
	}
	for (const char& c: text) {
		if (c == in){
			number++;
			if (index == pos)
				break;
		}
		++index;
	}
	for (const char& c: text) {
			if (c == type) {
				number2++;
				if (total - number +1 == number2) {
					break;
				}
			}
		index2++;
		}
	return index2;
}
