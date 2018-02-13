#include "umns.h"

using std::unordered_map;

UMNS::UMNS() {}

void UMNS::insert(const HostName& hn, const IPAddress& ip) {
  nameservers[hn] = ip;
}

bool UMNS::remove(const HostName& hn) {
  return nameservers.erase(hn) == 1;

}

IPAddress UMNS::lookup(const HostName& hn) const {
  auto nameserver = nameservers.find(hn);
  if (nameserver != nameservers.end())
    return nameserver->second;
  return NON_EXISTING_ADDRESS;
}
