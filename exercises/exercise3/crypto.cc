#include "crypto.h"

#include <string>
#include <random>


using std::string;

string Crypto::encrypt(const string& text, unsigned int key) {
	string crypt = "";
	for (auto c: text)
		crypt += (c + key) % 256;
	return crypt;
}

string Crypto::decrypt(const string& crypt, unsigned int key) {
	string text = "";
	for (auto c: crypt)
		text += (c - key) % 256;
	return text;
}
