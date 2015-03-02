#include <iostream>
using namespace std;

int main() {
	int d, i, j;
	cin >> d;
	
	bool found = false;
	for (i = 0; i <= d / 2; i++) {
		for (j = i; j * j - i * i <= d; j++) {
			if (j * j - i * i == d) {
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}
	
	if (found) {
		cout << i << " " << j << endl;
	}
	
	else {
		cout << "impossible" << endl;
	}

	
    return 0;
}
