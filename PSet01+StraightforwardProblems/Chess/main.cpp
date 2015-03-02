#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

// Sækjum lit reitar
bool getColor(char x, char y) {
	if (x == 'A' || x == 'C' || x == 'E' || x == 'G') {
		return y % 2;
	}
	return !(y % 2);
}

// Eru reitirnir með sama lit?
bool hasPath(char x1, char y1, char x2, char y2) {
	if (getColor(x1, y1) == getColor(x2, y2)) {
		return true;
	}
	return false;
}

// Eru reitirnir í sömu skálínu?
bool isReachable(char x1, char y1, char x2, char y2) {
	if (abs(x1 - x2) == abs(y1 - y2)) {
		return true;
	}
	return false;
}

// Erum við inni á borðinu?
bool outOfBounds(char x, char y) {
	return !('A' <= x && x <= 'H' && '1' <= y && y <= '8');
}

void findPath(char x1, char y1, char x2, char y2) {
	int nrOfMoves = 0;
	string moves;
	stringstream s1, s2, s3, s4, s5, s6;
	s1 << x1; s2 << y1; s3 << x2; s4 << y2;
	// Sami reitur
	if (x1 == x2 && y1 == y2) {
		moves = s1.str() + " " + s2.str();
	}
	// Reitir í sömu skálínu
	else if (isReachable(x1, y1, x2, y2)) {
		nrOfMoves++;
		moves = s1.str() + " " + s2.str() + " " + s3.str() + " " + s4.str();
	}
	// Reitir ekki í sömu skálínu
	else {
		nrOfMoves += 2;
		// Fyrst leitum við að góðri leið upp til hægri
		for (char x = x1 + 1, y = y1 + 1; !outOfBounds(x, y); x++, y++) {
			if (isReachable(x, y, x2, y2)) {
				stringstream s5, s6;
				s5 << x; s6 << y;
				moves = s1.str() + " " + s2.str() + " " + s5.str() + " " + s6.str() + " " + s3.str() + " " + s4.str();
				cout << nrOfMoves << " " << moves << endl;
				return;
			}
		}
		// Næst leitum við að góðri leið upp til vinstri
		for (char x = x1 - 1, y = y1 + 1; !outOfBounds(x, y); x--, y++) {
			if (isReachable(x, y, x2, y2)) {
				stringstream s5, s6;
				s5 << x; s6 << y;
				moves = s1.str() + " " + s2.str() + " " + s5.str() + " " + s6.str() + " " + s3.str() + " " + s4.str();
				cout << nrOfMoves << " " << moves << endl;
				return;
			}
		}
		// Þvínæst leitum við niður til vinstri
		for (char x = x1 - 1, y = y1 - 1; !outOfBounds(x, y); x--, y--) {
			if (isReachable(x, y, x2, y2)) {
				stringstream s5, s6;
				s5 << x; s6 << y;
				moves = s1.str() + " " + s2.str() + " " + s5.str() + " " + s6.str() + " " + s3.str() + " " + s4.str();
				cout << nrOfMoves << " " << moves << endl;
				return;
			}
		}
		// Að lokum leitum við niður til hægri
		for (char x = x1 + 1, y = y1 - 1; !outOfBounds(x, y); x++, y--) {
			if (isReachable(x, y, x2, y2)) {
				stringstream s5, s6;
				s5 << x; s6 << y;
				moves = s1.str() + " " + s2.str() + " " + s5.str() + " " + s6.str() + " " + s3.str() + " " + s4.str();
				cout << nrOfMoves << " " << moves << endl;
				return;
			}
		}
	}
	cout << nrOfMoves << " " << moves << endl;
}

int main () {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (!hasPath(x1, y1, x2, y2)) {
			cout << "Impossible" << endl;
		} else {
			findPath(x1, y1, x2, y2);
		}
	}
    return 0;
}
