#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;

int main() {
	// Check input and output of dates. Uncomment the following when you
	// have added operator>> and operator<<.
	bool cont = true;
	while (cont) {
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof()) {
			cont = false;
		} else if (!cin.good()) {
			cout << "Wrong input format or Invalid date" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Output: " << aDate << endl;
		}
	}


	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	cout << d1 << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		cout << d1 << endl;
	}

	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	cout << d2 <<endl;
	d2.next();
	cout << d2 <<  endl;
}
