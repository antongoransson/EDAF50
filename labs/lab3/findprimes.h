#ifndef FINDPRIMES_H
#define FINDPRIMES_H
#include <string>

class FindPrimes {
public:
  FindPrimes(unsigned int m);
  void print_primes() const;
  std::string get_prime() const;
  std::string::size_type get_largest_prime() const;
private:
  void calc_primes(std::string& primes);
  std::string primes;
};

#endif
