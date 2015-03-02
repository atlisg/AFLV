#include <iostream>
using namespace std;

int main () {
	int N, S, R;
	cin >> N >> S >> R;
	bool damagedKayaks[N];
	bool reserveKayaks[N];
	for (int i = 0; i < N; i++) {
		damagedKayaks[i] = false;
		reserveKayaks[i] = false;
	}
	
	for (int i = 0; i < S; i++) {
		int d;
		cin >> d;
		damagedKayaks[d - 1] = true;
	}
	
	for (int i = 0; i < R; i++) {
		int r;
		cin >> r;
		reserveKayaks[r - 1] = true;
	}
	
	for (int i = 0; i < N; i++) {
		if (damagedKayaks[i] == true && reserveKayaks[i] == true) {
			damagedKayaks[i] == false;
			reserveKayaks[i] == false;
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (damagedKayaks[i] == true) {
			if (i == 0) {
				if (reserveKayaks[i + 1] == true) {
					reserveKayaks[i + 1] = false;
				}
				else {
					cnt++;
				}
			}
			else if (i == N - 1) {
				if (reserveKayaks[i - 1] == false) {
					cnt++;
				}
			}
			else {
				if (reserveKayaks[i - 1] == false) {
					if (reserveKayaks[i + 1] == true) {
						reserveKayaks[i + 1] = false;
					}
					else {
						cnt++;
					}
				}
			}

		}
	}
	
	cout << cnt << endl;
	
    return 0;
}
