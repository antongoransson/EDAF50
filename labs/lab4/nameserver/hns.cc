#include "hns.h"

using std::hash;
using std::pair;

HNS::HNS(size_t s): size(s), nameservers(s) {}

void HNS::insert(const HostName& hn, const IPAddress& ip) {
  size_t i = hash<HostName>()(hn) % size;
  nameservers[i].push_back(make_pair(hn, ip));
}

bool HNS::remove(const HostName& hn) {
  size_t i = hash<HostName>()(hn) % size;
  auto nameserver = remove_if(nameservers[i].begin(), nameservers[i].end(),
  [&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (nameserver != nameservers[i].end()){
    nameservers[i].erase(nameserver);
    return true;
  }
  return false;
}

IPAddress HNS::lookup(const HostName& hn) const {
  size_t i = hash<HostName>()(hn) % size;
  auto nameserver = find_if(nameservers[i].begin(), nameservers[i].end(),
  [&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (nameserver != nameservers[i].end())
    return nameserver->second;
  return NON_EXISTING_ADDRESS;
}
