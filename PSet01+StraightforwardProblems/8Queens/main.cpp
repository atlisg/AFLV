#include <iostream>
using namespace std;

bool isValid(char table[][8]) {
	for (int i = 0; i < 8; i++) {
		int qCnt = 0;
		for (int j = 0; j < 8; j++) {
			if (table[i][j] == '*') {
				qCnt++;
				for (int h = 1, k = i + 1; k < 8; k++, h++) {
					if (table[k][j] == '*') {
						return false;
					}
					if ((j - h) >= 0) {
						if (table[k][j - h] == '*') {
							return false;
						}
					}
					if ((j + h) <= 7) {
						if (table[k][j + h] == '*') {
							return false;
						}
					}
				}
			}
		}
		if (qCnt != 1) {
			return false;
		}
	}
	return true;
}

int main () {
	char table[8][8];
	for (int i = 0; i < 8; i++) {
		string inp;
		cin >> inp;
		for (int j = 0; j < 8; j++) {
			table[i][j] = inp[j];
		}
	}

	if (isValid(table)) {
		cout << "valid";
	} else {
		cout << "invalid";
	}

    return 0;
}

