#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;
using std::map;
using std::pair;
using std::sort;
using std:: vector;

void print_words(map<string, int>&words) {
  vector<pair<string, int>> count(words.begin(), words.end());
  sort(count.begin(), count.end(),
  []( pair<string, int>& a, pair<string, int>& b){ return a.second != b.second ? a.second > b.second : a.first > b.first;});
  for (size_t i = 0; i < count.size() && i < 20;++i)
    cout << count[i].first << " " << count[i].second << endl;
}

void count_words(std::istream& input, map<string, int>&words) {
  string word;
  while(input >> word)
      words[word] += 1;
}

int main(int argc, char **argv) {
  map<string, int> words;
  for(int i = 1; i != argc; ++i) {
    ifstream input(argv[i]);
    if(input.is_open()) {
      count_words(input, words);
    } else {
      cout << "File: " << argv[i] << " could not be opened" << endl;
    }
  }
  print_words(words);
}
