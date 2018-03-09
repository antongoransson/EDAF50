#include <iterator>
class TextIterator {
public:
  TextIterator(std::vector<std::string>* l, size_t cl): lines(l), curr_line(cl), curr_pos(0) {}

   char& operator*(){
    return (*lines)[curr_line][curr_pos];
  }

  bool operator!=(const TextIterator& ti) {
    return lines != ti.lines || curr_line != ti.curr_line || curr_pos != ti.curr_pos;// ? curr_pos != ti.curr_pos : true;
  }

  TextIterator& operator++() {
    curr_pos++;
    if(curr_pos == (*lines)[curr_line].size()) {
      curr_pos = 0;
      curr_line++;
    }
    return *this;
  }

private:
  std::vector<std::string>* lines;
  size_t curr_line;
  size_t curr_pos;
};
