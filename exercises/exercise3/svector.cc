/*
 * Class SVector: implementation.
 */

#include "svector.h"

SVector::SVector(size_t size) : n(size), v(new int[n]) {}

SVector::SVector(const SVector& s): n (s . n ) , v ( new int[n] ) {
	for(size_t i = 0; i < n; i++)
		v[i] = s.v[i];
}


SVector::~SVector() {
	delete[] v;
}

size_t SVector::size() const {
	return n;
}

int SVector::get(size_t i) const {
	return v[i];
}

void SVector::set(size_t i, int value) {
	v[i] = value;
}
