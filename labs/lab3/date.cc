#include <ctime>  // time and localtime
#include "date.h"
#include <iomanip>
#include <ios>
#include <algorithm>

using std::setw;
using std::setfill;
using std::ostream;
using std::istream;
using std::ios_base;
using std::string;
using std::count;
using std::getline;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d): year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day++;
	if (day > daysPerMonth[month -1]) {
		day = 1;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}
ostream& operator<<(ostream& os, const Date& d) {
	os << setw(4) << setfill('0') <<  d.year << '-';
	os << setw(2) << setfill('0') << d.month << '-';
	os << setw(2) << setfill('0') << d.day;
	return os;
}

istream& operator>>(istream& is, Date& d) {
	string line;
	getline(is, line);
	size_t n = count(line.begin(), line.end(), '-');
	if (n != 2){
		is.setstate (ios_base::failbit);
		return is;
	}
	string year = line.substr(0, 4);
	if (count(year.begin(), year.end(), '-') > 0 ){
		is.setstate (ios_base::failbit);
		return is;
	}
	d.year = stoi(year);
	string month = line.substr(5, 2);
	if (d.month > 12 || count(month.begin(), month.end(), '-') > 0){
		is.setstate (ios_base::failbit);
		return is;
	}
	d.month = stoi(month);
	string day = line.substr(8, 2);
	if (d.day > d.daysPerMonth[d.month -1] || count(day.begin(), day.end(), '-') > 0) {
		is.setstate (ios_base::failbit);
		return is;
	}
	d.day = stoi(day);
	return is;
}
