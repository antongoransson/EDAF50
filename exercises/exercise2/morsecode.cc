#include "morsecode.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <map>
using namespace std;
using std::cout;
using std::endl;
using std::map;

MorseCode::MorseCode() {
	// map<string, string> text_map;
	// map<string, string> code_map;
	string line;
 	ifstream input ("morse.def");
	 if (input.is_open()) {
		 while (getline (input, line)) {
		 	stringstream ss(line);
     	string letter;
			string c;
			ss >> letter;
			ss >> c;
			table[letter[0] - 'a'] = c;
		 }
		 input.close();
	 }
 else cout << "Unable to open file";
}

string MorseCode::encode(const string& text) const {
	string code = "";
	string temp ;
	stringstream ss(text);
	while (ss >> temp) {
		if (temp[0] >= 'a' && temp[0] <= 'z'){
			code += table[temp[0] -'a'];
			code += ' ';
		}
	}
	return code;
}

string MorseCode::decode(const string& code) const {
	string decoded = "";
	string temp;
	stringstream ss(code);
	while (ss >> temp) {
		if (temp != " "){
			for (int i = 0; i <= 25; i++) {
				if (table[i] == temp)
					decoded += i + 'a';
			}
		}
	}
	return decoded;
}
