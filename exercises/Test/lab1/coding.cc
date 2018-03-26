#include "coding.h"

unsigned char encode(char& text) {
  return text + 5;
}
unsigned char decode(char& text) {
  return text - 5;
}
