#include <utility>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
template <typename K, typename V>

class AV {
public:
  using key_type = K;
  using mapped_type = V;
  using value_type = std::pair<K,V>;
  using iterator = typename std::vector<value_type>::iterator;

  AV(){}
	iterator begin() { return map.begin();}
	iterator end() { return map.end(); }

  iterator find(const key_type& key) {
      auto x = std::lower_bound(map.begin(), map.end(), key, less);
      if ((x != map.end()) && !(key < x->first)) return x;
    return map.end();
   }
  void insert(const value_type& p) { map.push_back(p); std::sort(map.begin(), map.end()); }
private:
  std::vector<value_type> map;
  static bool less (const value_type& p, const key_type& k) { return p.first < k; }
};
