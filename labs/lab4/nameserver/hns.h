#include "nameserverinterface.h"
#include <vector>
#include <algorithm>
#include <functional>

class HNS : public NameServerInterface {
public:
  HNS(size_t s);
  void insert(const HostName& hn, const IPAddress& ip) override;
  bool remove(const HostName& hn) override;
  IPAddress lookup(const HostName& hn) const override;
private:
  size_t size;
  std::vector<std::vector<std::pair<HostName, IPAddress>>> records;
};
