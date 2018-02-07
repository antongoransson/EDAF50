#ifndef TAGREMOVER_H
#define TAGREMOVER_H

#include <iostream>

class TagRemover {
public:
  TagRemover(std::istream& is);
  TagRemover(const std::string& s);
  void print(std::ostream& os) const;
  void removeAll(std::string& text);
  std::string getText() const;
private:
  std::string text;
  void translateSpecialChars(std::string& text);
  void removeTags(std::string& text);

};

#endif
