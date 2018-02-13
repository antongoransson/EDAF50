#include "mns.h"
using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;
using std::map;

MNS::MNS() {
  string line;
  HostName hn;
  IPAddress ip;
	ifstream input ("nameserverdata.txt");
	 if (input.is_open()) {
		 while (getline (input, line)) {
			 istringstream ss(line);
			 ss >> hn;
			 ss >> ip;
       nameservers[hn] = ip;
		 }
		 input.close();
	 }
 else cout << "Unable to open file";
}

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
