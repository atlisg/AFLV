#include <iostream>
using namespace std;

int main () {
	string healthy, infected;
	cin >> healthy >> infected;
	
	int virusBegin;
	int virusLength;
	int maxLength = max(healthy.length(), infected.length());
	
	for (int i = 0; i < maxLength; i++) {
		if (healthy[i] != infected[i]) {
			virusBegin = i;
			break;
		}
	}
	
	for (int i = healthy.length() - 1, j = infected.length() - 1; i >= virusBegin && j >= virusBegin; i--, j--) {
		if (healthy[i] != infected[j]) {
			virusLength = j - virusBegin + 1;
			break;
		}
	}
	
	if (virusLength == 0 && healthy.length() < infected.length()) {
		virusLength = infected.length() - healthy.length();
	}
	
	cout << virusLength << endl;
	
    return 0;
}
