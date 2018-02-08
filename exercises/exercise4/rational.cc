#include "rational.h"
#include <stdlib.h>

using std::cout;
using std::endl;
using std::abs;
using std::ostream;
using std::string;
using std::to_string;

Rational::Rational(): numerator(0), denumerator(1) {
  simplify();
}
Rational::Rational(int a): numerator(a), denumerator(1) {
  simplify();
}
Rational::Rational(int a, int b): numerator(a), denumerator(b) {
  simplify();
}

Rational& Rational::operator=(const int a) {
  numerator = a;
  simplify();
  return *this;
}

Rational& Rational::operator=(const Rational r) {
  numerator = r.numerator;
  denumerator = r.denumerator;
  simplify();
  return *this;
}

Rational Rational::operator+(const Rational r) {
  Rational t(numerator * r.denumerator + r.numerator * denumerator, denumerator * r.denumerator);
  simplify();
  return t;
}

Rational& Rational::operator+=(const Rational r) {
  numerator = numerator * r.denumerator + r.numerator * denumerator;
  denumerator = denumerator * r.denumerator;
  simplify();
  return *this;
}

void Rational::simplify() {
  unsigned int gcd = binaryGCD(numerator, denumerator);
  numerator /= gcd;
  denumerator /= gcd;
}

unsigned int Rational::binaryGCD(int& a, int& b) {
  int g{1}, t, u{a}, v{b};
  while ((u & 0x1)== 0 && (v & 0x1) == 0) {
    u >>= 1;
    v >>= 1;
    g <<= 1;
  }
  while (u > 0) {
    if ((u & 0x1) == 0) u >>= 1;
    else if ((v & 0x1) == 0) v >>= 1;
    else {
      t = abs(u - v) >> 1;
      if (u < v) v = t;
      else u = t;
    }
  }
  return  v * g;
}

ostream& operator<<(ostream& o, const Rational& r) {
  string s = to_string(r.numerator);
  if(! (r.numerator == 0 || r.denumerator == 1))
    s += "/" + to_string(r.denumerator);
  o << s;
  return o;
  }
