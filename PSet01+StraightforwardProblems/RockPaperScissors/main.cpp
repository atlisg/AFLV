#include <iostream>
using namespace std;

int main () {
	int n;
	cin >> n;
	while (n != 0) {
		int k;
		cin >> k;
		int totGames = (k * n * (n - 1)) / 2;
		// heldur utan um fjölda vinninga hvers leikmanns
		int playerWins[n];
		for (int i = 0; i < n; i++) {
			playerWins[i] = 0;
		}
		// heldur utan um fjölda tapa hvers leikmanns
		int playerLosses[n];
		for (int i = 0; i < n; i++) {
			playerLosses[i] = 0;
		}
		for (int i = 0; i < totGames; i++) {
			int p1, p2;
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			// skráum vinninga og töp leikmanna
			if (m1 == "rock") {
				if (m2 == "paper") {
					playerWins[p2 - 1]++;
					playerLosses[p1 - 1]++;
				}
				if (m2 == "scissors") {
					playerWins[p1 - 1]++;
					playerLosses[p2 - 1]++;
				}
			}
			if (m1 == "paper") {
				if (m2 == "scissors") {
					playerWins[p2 - 1]++;
					playerLosses[p1 - 1]++;
				}
				if (m2 == "rock") {
					playerWins[p1 - 1]++;
					playerLosses[p2 - 1]++;
				}
			}
			if (m1 == "scissors") {
				if (m2 == "rock") {
					playerWins[p2 - 1]++;
					playerLosses[p1 - 1]++;
				}
				if (m2 == "paper") {
					playerWins[p1 - 1]++;
					playerLosses[p2 - 1]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (playerWins[i] == 0 && playerLosses[i] == 0) {
				cout << "-" << endl;
			} else {
				cout.setf(ios::fixed,ios::floatfield);
				cout.precision(3);
				cout << static_cast<double> (playerWins[i]) 
				/ (static_cast<double> (playerWins[i]) + static_cast<double> (playerLosses[i])) << endl;
			}
		}
		cout << endl;
		cin >> n;
	}
    return 0;
}
