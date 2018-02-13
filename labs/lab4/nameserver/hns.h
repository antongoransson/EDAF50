#include "nameserverinterface.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

class HNS : public NameServerInterface {
public:
  HNS();
  void insert(const HostName& hn, const IPAddress& ip) override;
  bool remove(const HostName& hn) override;
  IPAddress lookup(const HostName& hn) const override;
private:
  std::vector<std::pair<HostName, unsigned int>> nameservers;
};
