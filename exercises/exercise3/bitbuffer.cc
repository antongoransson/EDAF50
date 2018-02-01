#include "bitbuffer.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

BitBuffer::BitBuffer(std::ostream& out): o(out), bits("") {}

void BitBuffer::put(bool b) {
  bits += to_string(b);
  if (bits.length() == 8){
    o.put( std::stoi(bits, nullptr, 2););
    bits = "";
  }
}


/* THEIR SOLUTION
BitBuffer::BitBuffer(std::ostream& out) : os(out), n_bits(0) {}

void BitBuffer::put(bool b) {
	byte = (byte << 1) | b;
	if (++n_bits == 8) {
		os.put(byte);
		n_bits = 0;
	}
}

*/
