#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational {
public:
  Rational();
  Rational(int a, int b);
  Rational(int a);
  Rational& operator=(const int a);
  Rational& operator=(const Rational a);
  Rational operator+(const Rational r);
  Rational& operator+=(const Rational r);
  friend std::ostream& operator<<(std::ostream& o, const Rational& r);
  void simplify();
private:
  unsigned int binaryGCD(int& a, int& b);
  int numerator;
  int denumerator;
};



#endif
