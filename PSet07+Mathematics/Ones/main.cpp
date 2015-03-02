#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n;
	
	while (cin >> n) {
		int curr = 1, prev = 1;
		for (int j = 0; true; j++) {
			if (j != 0) {
				curr = (10 * prev + 1) % n;
			}

			if (curr % n == 0) {
				cout << j + 1 << endl;
				break;
			}
			prev = curr % n;
		}
	}

    return 0;
}