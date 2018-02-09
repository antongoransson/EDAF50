#include <utility>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
template <class K, class V>

class AV {
public:
  typedef typename std::vector<std::pair<K,V>>::iterator iterator;
  AV(){}
	iterator begin() { return map.begin();}
	iterator end() { return map.end(); }
  iterator find(const K& key) {
    std::binary_search(map.begin(), map.end(), key);
   }
  void insert(std::pair <K, V> p) { map.push_back(p); std::sort(map.begin(), map.end()); }
private:
  std::vector<std::pair<K, V>> map;
};
