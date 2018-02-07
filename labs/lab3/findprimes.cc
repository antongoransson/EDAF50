#include "findprimes.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

FindPrimes::FindPrimes(unsigned int m) :primes(m + 1, 'P') {
  primes[0] = 'C';
  primes[1] = 'C';
  calc_primes(primes);
}

string FindPrimes::get_prime() const {
  return primes;
}

void FindPrimes::calc_primes(string& primes) {
  string::size_type pos = 2;
  while (pos < primes.length() && pos != string::npos) {
    string::size_type i = 2;
    while (i < primes.length() && i != string::npos) {
      if (i % pos == 0 && i != pos)
        primes[i] = 'C';
      i = primes.find("P",i + 1);
    }
    pos = primes.find("P",pos + 1);
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
