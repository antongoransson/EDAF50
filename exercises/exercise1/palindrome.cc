
#include <iostream>
#include <string>

using namespace std;

bool ispalindrome(string s) {
  int start = 0;
  int end = s.size() - 1;
  while (s[start] == s[end] && start < end) {
    start ++;
    end--;
  }
  return start >= end;
}

int main() {
  string s;
  cout << "Welcome to is a palindrome!" << endl << "Enter word: ";
  while (cin >> s) {
    if (ispalindrome(s))
      cout << "True" << endl;
    else
      cout << "False" << endl;
    cout << "Enter word: ";
  }
}
