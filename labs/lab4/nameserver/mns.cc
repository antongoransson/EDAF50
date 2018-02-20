#include "mns.h"
using std::map;

MNS::MNS() {}

void MNS::insert(const HostName& hn, const IPAddress& ip) { records[hn] = ip; }

bool MNS::remove(const HostName& hn) { return records.erase(hn); }

IPAddress MNS::lookup(const HostName& hn) const {
  auto record = records.find(hn);
  if (record != records.end())
    return record->second;
  return NON_EXISTING_ADDRESS;
}
