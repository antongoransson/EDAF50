#include "mns.h"
using std::map;

MNS::MNS() {}

void MNS::insert(const HostName& hn, const IPAddress& ip) {
  nameservers[hn] = ip;
}

bool MNS::remove(const HostName& hn) {
  return nameservers.erase(hn) == 1;

}

IPAddress MNS::lookup(const HostName& hn) const {
  auto nameserver = nameservers.find(hn);
  if (nameserver != nameservers.end())
    return nameserver->second;
  return NON_EXISTING_ADDRESS;
}
