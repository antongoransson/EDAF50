#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

#include <iostream>

class Square : public Shape {
public:
	void print() const {
		std::cout << "I'm a Square" << std::endl;
	}
	Shape* clone() const {
		return new Square(*this);
	}
};

#endif
