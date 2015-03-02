#include <iostream>
using namespace std;

int main() {
	
	string s;
	getline(cin, s);
	
	int cnt[26];
	
	for (int i = 0; i < 26; i++) {
		cnt[i] = 0;
	}
	
	for (int i = 0; i < s.length(); i++) {
		int letter = s[i] - 'a';
		cnt[letter]++;
	}
	
	int cntOdd = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1) {
			cntOdd++;
		}
	}
	
	if (cntOdd < 1) {
		cout << 0 << endl;
	}
	else {
		cout << cntOdd - 1 << endl;
	}

    return 0;
}
