#include "umns.h"

using std::unordered_map;

UMNS::UMNS() {}

void UMNS::insert(const HostName& hn, const IPAddress& ip) { records[hn] = ip; }

bool UMNS::remove(const HostName& hn) { return records.erase(hn); }

IPAddress UMNS::lookup(const HostName& hn) const {
  auto record = records.find(hn);
  if (record != records.end())
    return record->second;
  return NON_EXISTING_ADDRESS;
}
