#include "hns.h"

using std::hash;
using std::pair;

HNS::HNS(size_t s): size(s), records(s) {}

void HNS::insert(const HostName& hn, const IPAddress& ip) {
  size_t i = hash<HostName>()(hn) % size;
  records[i].push_back(make_pair(hn, ip));
}

bool HNS::remove(const HostName& hn) {
  size_t i = hash<HostName>()(hn) % size;
  auto record = remove_if(records[i].begin(), records[i].end(),
    [&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (record != records[i].end()){
    records[i].erase(record);
    return true;
  }
  return false;
}

IPAddress HNS::lookup(const HostName& hn) const {
  size_t i = hash<HostName>()(hn) % size;
  auto record = find_if(records[i].begin(), records[i].end(),
    [&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (record != records[i].end())
    return record->second;
  return NON_EXISTING_ADDRESS;
}
