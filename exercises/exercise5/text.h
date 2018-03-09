#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>
#include <iostream>
#include <textiterator.h>

class Text {
public:
	void addLine(const std::string& line) { lines.push_back(line); }
	using iterator = TextIterator;
	iterator begin() { return iterator(&lines, 0); }
	iterator end() { return iterator(&lines, lines.size()); }

private:
	std::vector<std::string> lines;
};

#endif
