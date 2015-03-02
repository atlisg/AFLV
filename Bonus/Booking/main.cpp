#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct booking {
	int year, month, day, hour, min;
	bool arriv;
	booking(int ye, int mo, int da, int ho, int mi, bool in) {
		year  = ye;
		month = mo;
		day   = da;
		hour  = ho;
		min   = mi;
		arriv = in;
	}
};

bool operator < (const booking& l, const booking& r) {
	if (l.year < r.year) {
		return true;
	}
	if (l.year == r.year && l.month < r.month) {
		return true;
	}
	if (l.year == r.year && l.month == r.month && l.day < r.day) {
		return true;
	}
	if (l.year == r.year && l.month == r.month && l.day == r.day && l.hour < r.hour) {
		return true;
	}
	if (l.year == r.year && l.month == r.month && l.day == r.day && l.hour == r.hour && l.min < r.min) {
		return true;
	}
	if (l.year == r.year && l.month == r.month && l.day == r.day && l.hour == r.hour && l.min == r.min && !l.arriv && r.arriv) {
		return true;
	}
	return false;
}

int minRooms(vector<booking> &bookings) {
	
	sort(bookings.begin(), bookings.end());
	
/*	for (int i = 0; i < bookings.size(); i++) {
		cout << "year: " << bookings[i].year << " month: " << bookings[i].month << " day: " << bookings[i].day 
		<< " hour: " << bookings[i].hour << " min: " << bookings[i].min << endl;
	}
*/	
	int rooms = 0;
	int maxR  = 0;
	
	for (int i = 0; i < bookings.size(); i++) {
		if (bookings[i].arriv) {
			rooms++;
		}
		else {
			rooms--;
		}
		maxR = max(maxR, rooms);
	}
	
	return maxR;
}

int main() {
	
	int T;
	cin >> T;
	
	while (T > 0) {
		
		int B, C;
		cin >> B >> C;
		
		vector<booking> bookings;
		string sDummy;
		char cDummy;
		int year, month, day, hour, min;
		for (int i = 0; i < B; i++) {
			cin >> sDummy >> year >> cDummy >> month >> cDummy >> day >> hour >> cDummy >> min;
			booking inp = booking(year, month, day, hour, min, true);
			bookings.push_back(inp);
			
			cin >> year >> cDummy >> month >> cDummy >> day >> hour >> cDummy >> min;
			inp = booking(year, month, day, hour, min, false);
			bookings.push_back(inp);
		}
		
		// bætum hreinsunartímanum við brottfarartímann
		for (int i = 0; i < bookings.size(); i++) {
			if (!bookings[i].arriv) {
				bookings[i].min += C;
				if (bookings[i].min > 59) {
					int tmp = bookings[i].min / 60;
					bookings[i].min = bookings[i].min % 60;
					bookings[i].hour += tmp;
					if (bookings[i].hour > 23) {
						bookings[i].hour = bookings[i].hour % 24;
						bookings[i].day++;
						if (bookings[i].day > 28) {
							if (bookings[i].year != 2016 && bookings[i].month == 2) {
								bookings[i].day = 1;
								bookings[i].month++;
							}
							else if (bookings[i].day > 29 && bookings[i].year == 2016 && bookings[i].month == 2) {
								bookings[i].day = 1;
								bookings[i].month++;
							}
							else if (bookings[i].day > 30 && (bookings[i].month == 4 || bookings[i].month == 6 
															   || bookings[i].month == 9 || bookings[i].month == 11)) {
								bookings[i].day = 1;
								bookings[i].month++;
							}
							else if	(bookings[i].day > 31) {
								bookings[i].day = 1;
								bookings[i].month++;
							}
						}
						if (bookings[i].month > 12) {
							bookings[i].month = 1;
							bookings[i].year++;
						}
					}
				}
			}
		}
		
		cout << minRooms(bookings) << endl;
		
		T--;
	}
	
    return 0;
}
