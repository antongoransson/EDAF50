#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>
#include <iostream>
class Text {
public:
	void addLine(const std::string& line) { lines.push_back(line); }
	typedef std::string::iterator iterator;
  typedef std::string::const_iterator const_iterator;
	iterator begin() { return lines[0].begin();}
	iterator end() { return lines[0].end(); }

private:
	std::vector<std::string> lines;
};

#endif
