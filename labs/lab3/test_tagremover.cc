#include "tagremover.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

void testTagRemove() {
  string test = "Here <tag> is a tag another one <tag sadasdadas > woo";
  string truestr = "Here is a tag another one woo";
  TagRemover tr(test);
  string s = tr.getText();
  if (s == truestr)
    cout << "Remove Tags Success" << endl;
  else
    cout << "Remove Tags Failed" << endl;
  tr.print(cout);  
}
void testRemoveSpecialChars() {
  string test = "Here &lt is a string &amp chars &gt with spec&nbspchars &amp other fun stuff";
  string truestr = "Here < is a string & chars > with spec chars & other fun stuff";
  TagRemover tr(test);
  string s = tr.getText();
  if (s == truestr)
    cout << "Translate Special Chars Success" << endl;
  else
    cout << "Translate Special Chars Failed" << endl;
}

int main() {
  testTagRemove();
  testRemoveSpecialChars();
  TagRemover tr(cin);
  tr.print(cout);
}
