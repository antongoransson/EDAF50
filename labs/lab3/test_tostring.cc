#include <string>
#include <iostream>
#include <sstream>
#include <date.h>
#include <iomanip>
#include <vector>
#include <findprimes.h>
#include <stdexcept>

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::istringstream;

ostream& operator<<(ostream& os, const vector<string>& v) {
	for (const string& s : v) {
		os << s << " ";
	}
	return os;
}

template <typename T>
string toString(T obj) {
  ostringstream os;
  os << obj;
  return os.str();
}

template <typename T>
T string_cast(string s) {
  istringstream ss(s);
  T obj;
  ss >> obj;
  if (ss.fail())
    throw std::invalid_argument("Invalid argument");
  return obj;
}

int main() {
  try {
    int x = string_cast<int>("5");
    double y = string_cast<double>("5.33231");
    vector<string> v = {"Hej", "på", "dig", "din", "rackare"};
    Date d = string_cast<Date>("2018-05-20");
    string xs = toString(x);
    cout << "\t" << xs << " (5)" << endl;

    string ys = toString(y);
    cout << "\t" << ys << " (5.33231)" << endl;

    string vs = toString(v);
    cout << "\t" << vs << "(Hej på dig din rackare)" << endl;

    string ds = toString(d);
    cout << "\t" << ds << " (2018-05-20)";
  } catch (std::invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
  }
}
