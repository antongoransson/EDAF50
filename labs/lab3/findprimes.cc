#include "findprimes.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

FindPrimes::FindPrimes(unsigned int m) {
  primes = "CC" + string(m - 1, 'P');
  calc_primes(primes);
}

string FindPrimes::get_prime() const {
  return primes;
}

void FindPrimes::calc_primes(string& primes) {
  string::size_type pos = primes.find("P");
  while (pos != string::npos) {
    string::size_type i = pos;
    while (i != string::npos) {
      if (i % pos == 0 && i != pos)
        primes[i] = 'C';
      i = primes.find("P", i + 1);
    }
    pos = primes.find("P", pos + 1);
  }
}

void FindPrimes::print_primes() const {
  for (string::size_type i = 0; i < primes.length(); ++i) {
    if (primes[i] == 'P')
      cout << i << endl;
  }
}

string::size_type FindPrimes::get_largest_prime() const {
  return primes.rfind('P');
}
