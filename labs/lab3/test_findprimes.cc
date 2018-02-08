#include "findprimes.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void testM5(){
  FindPrimes fp(5);
  string res = "CCPPCP";
  if (fp.get_prime() == res)
    cout << "M=5 Success" << endl;
  else
    cout << "M=5 Failed" << endl;
}
void testM7() {
  FindPrimes fp(7);
  string res = "CCPPCPCP";
  if (fp.get_prime() == res)
    cout << "M=7 Success" << endl;
  else
    cout << "M=7 Failed" << endl;
}

void testM11() {
  FindPrimes fp(11);
  string res = "CCPPCPCPCCCP";
  if (fp.get_prime() == res)
    cout << "M=11 Success" << endl;
  else
    cout << "M=11 Failed" << endl;
}

void testM35() {
  FindPrimes fp(35);
  string res = "CCPPCPCPCCCPCPCCCPCPCCCPCCCCCPCPCCCC";
  if (fp.get_prime() == res)
    cout << "M=35 Success" << endl;
  else
    cout << "M=35 Failed" << endl;
}

void print200Primes() {
  FindPrimes fp(200);
  fp.print_primes();
}

void testFindLargest() {
  unsigned int prime = 99991;
  FindPrimes fp(100000);
  cout << fp.get_largest_prime() << endl;
  if (fp.get_largest_prime() == prime)
    cout << "Largest Prime success" << endl;
  else
    cout << "Largest Prime Failed" << endl;
}

int main() {
  testM5();
  testM7();
  testM11();
  testM35();
  print200Primes();
  testFindLargest();

}
