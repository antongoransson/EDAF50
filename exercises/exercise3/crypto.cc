#include "crypto.h"
#include <string>
#include <random>


using std::string;
using std::uniform_int_distribution;

string Crypto::encrypt(const string& text, unsigned int key) {
	std::default_random_engine e(key);
	std::uniform_int_distribution<unsigned> dist(0, 255);
	string crypt = "";
	for (auto c: text)
		crypt += (c + dist(e)) % 256;
	return crypt;
}

string Crypto::decrypt(const string& crypt, unsigned int key) {
	std::default_random_engine e(key);
	std::uniform_int_distribution<unsigned> dist(0, 255);
	string text = "";
	for (auto c: crypt)
		text += (c - dist(e)) % 256;
	return text;
}
