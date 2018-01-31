#include <fstream>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::transform;
using std::vector;
using std::sort;



string createTrigrams(const string& text) {
  string s = text;
  string trigrams = "";
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  string::size_type nbr_trigrams;
  if (s.length() < 3)
    nbr_trigrams = 0;
  else
    nbr_trigrams = s.length() - 2;
  vector<string> temp(nbr_trigrams);
  for(string::size_type i = 0; i < nbr_trigrams; i++)
      temp[i] = s.substr(i, 3);
  sort(temp.begin(), temp.end());
  for(const auto& t : temp)
      trigrams += t + " ";
  return s + " " + to_string(nbr_trigrams) + " " + trigrams;
}

int main() {
  string line;
 	ifstream input ("words");
  ofstream output;
  output.open ("words.txt");
	 if (input.is_open()) {
		 while (getline (input, line)) {
      string trigram = createTrigrams(line);
      output << trigram << endl;
		 }
		 input.close();
	 }
 else cout << "Unable to open file";
 return 0;
}
