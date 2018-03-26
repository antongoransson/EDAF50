#include <iostream>
#include <vector>
#include<iterator>
#include<algorithm>
#include <deque>
#include "sqlite3.h" 
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::deque;
using std::cin;
using std::istream_iterator;
using std::ostream_iterator;
// int main() {
// //   int x = 6 + 3 * 4 / 2 + 2;
// //   int *q = 0;
// //   const int &r1 = 42;
// //   int ia[] = { 1,2,3 };
// //   // int last = *(ia+2); // last = 3;
// //   int last = *ia + 4;
// //   vector<int> m(5, 4);
// //   begin(m);
// //   string a = "ADSDDASDA";
// //   for (auto it = begin(a); it != end(a); ++it)
// //     cout << *it;
// //   std::cout << "Hello World" << last << std::endl;
//   std::ostream_iterator<int> out_iter(cout, "\n");
//   std::istream_iterator<int> in_iter(std::cin), eof;
//   vector<int> vec(in_iter, eof);
//   copy(vec.begin(), vec.end(), out_iter);
//   // while (in_iter != eof)
//   //   *out_iter++ = *in_iter++;
//   return 0;
// }
template<typename InputIterator, typename OutputIterator>
OutputIterator adjacent_difference1(InputIterator first, InputIterator last, OutputIterator result) {
  if (first == last) {
    return result;
  }
  InputIterator curr = first++;
  *result++ = *curr;
  while(first != last) {
    *result++= *first - *curr;
    curr = first++;
  }
  return result;
}

int main() {
  // deque<int> a;
  // copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(a));
  std::istream_iterator<int> in_iter(std::cin), eof;
  std::ostream_iterator<int> out_iter(cout, " ");
  vector<int> a (in_iter, eof);
  copy(a.begin(), a.end(), out_iter);
  cout << endl;
  vector<int> b(a.size());
  while (a.size() > 1) {
    // deque<int> b;
    adjacent_difference1(a.begin(), a.end(), b.begin());
    // b.pop_front();
    // a.swap(b);
    b = vector<int>(b.begin() + 1, b.end());
    a = b;
    copy(a.begin(), a.end(), out_iter);
    cout << endl;
  }
}
