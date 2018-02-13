#include "vns.h"

using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;
using std::find_if;
using std::pair;

VNS::VNS() {}

void VNS::insert(const HostName& hn, const IPAddress& ip) {
  nameservers.push_back(make_pair(hn, ip));
}

bool VNS::remove(const HostName& hn) {
  auto nameserver = remove_if (nameservers.begin(), nameservers.end(),
   [&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (nameserver != nameservers.end()){
    nameservers.erase(nameserver);
    return true;
  }
  return false;
}

IPAddress VNS::lookup(const HostName& hn) const {
  auto nameserver = find_if(nameservers.begin(), nameservers.end(),
[&hn](const pair<HostName, IPAddress>& p) { return p.first == hn; });
  if (nameserver != nameservers.end())
    return nameserver->second;
  return NON_EXISTING_ADDRESS;
}
