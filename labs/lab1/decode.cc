#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "coding.h"

using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::string;

int main(int argc, char** argv)
{
  string line;
  string code = "";
  string file{argv[1]};
  ifstream input (file + ".enc");
  if (input.is_open()) {
   while (getline (input, line)) {
     for(auto& c: line) {
       code += decode(c);
     }
     code += '\n';
   }
   input.close();
  } else cout << "Unable to open file";
  cout << code;
  ofstream output;
  output.open (file + ".dec");
  output << code;
  output.close();
}
