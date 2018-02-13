#include "vns.h"

using std::pair;

VNS::VNS() {}

void VNS::insert(const HostName& hn, const IPAddress& ip) {
  records.push_back(make_pair(hn, ip));
}

bool VNS::remove(const HostName& hn) {
  auto record = remove_if (records.begin(), records.end(),
   [&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (record != records.end()){
    records.erase(record);
    return true;
  }
  return false;
}

IPAddress VNS::lookup(const HostName& hn) const {
  auto record = find_if(records.begin(), records.end(),
[&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (record != records.end())
    return record->second;
  return NON_EXISTING_ADDRESS;
}
