#ifndef FINDPRIMES_H
#define FINDPRIMES_H
#include <string>

class FindPrimes {
public:
  FindPrimes(unsigned int m);
  std::string get_prime() const;
  void print_primes() const;
  std::string::size_type get_largest_prime() const;
private:
  void calc_primes(std::string& primes);
  std::string primes;
};

#endif
