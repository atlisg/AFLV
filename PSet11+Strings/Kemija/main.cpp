#include <iostream>
#include <string>
using namespace std;

string decode(string s) {
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			s.erase(i, 2);
		}
	}
	
	return s;
}

int main() {
	
	string line;
	getline(cin, line);
	
	cout << decode(line) << endl;
	
    return 0;
}
