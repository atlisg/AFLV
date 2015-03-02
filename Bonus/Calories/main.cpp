#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	
	string inp;
	getline(cin, inp);
	
	while (true) {
		
		double totCal = 0.0;
		double totFat = 0.0;
		
		while (inp != "-") {
			string s[5];
			stringstream ss(inp);
			
			// splitta inputinu
			for (int i = 0; ss.good() && i < 5; i++) {
				ss >> s[i];
			}
			
			double lineFatC = 0.0;
			double lineFatP = 0.0;
			pair<double, char> fat;
			
			// processa hvert item
			for (int i = 0; i < 5; i++) {
				
				char unit = s[i][s[i].length() - 1];
				string sn = s[i].erase(s[i].length() - 1);
				istringstream iss(sn);
				double dn;
				iss >> dn;

				if (unit == '%') {
					lineFatP += dn;
				}
				else if (unit == 'C') {
					lineFatC += dn;
				}
				else {
					if (i == 0) {
						dn *= 9.0;
					}
					else if (i == 4) {
						dn *= 7.0;
					}
					else {
						dn *= 4.0;
					}
					lineFatC += dn;
				}
				
				if (i == 0) {
					fat.first = dn;
					fat.second = unit;
				}
			}
			
			// framkvæmi reikninga
			lineFatC = lineFatC / (1.0 - (lineFatP * 0.01));
			totCal += lineFatC;
			if (fat.second == '%') {
				fat.first = (fat.first * 0.01) * lineFatC;
				totFat += fat.first;
			}
			else {
				totFat += fat.first;
			}
			
			getline(cin, inp);
		}
		
		double toPrint = totFat / totCal * 100;
		cout << fixed << setprecision(0) << toPrint << "%" << endl;
		
		getline(cin, inp);
		if (inp == "-") {
			break;
		}
	}
	
    return 0;
}
