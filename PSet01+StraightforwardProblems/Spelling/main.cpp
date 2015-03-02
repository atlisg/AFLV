#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main () {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string inp;
		getline(cin, inp);
		if (inp == "") {
			getline(cin, inp);
		}
		string keypad[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		stringstream ss;
		ss << i + 1;
		string outp = "Case #" + ss.str() + ": ";
		for (int c = 0; c < inp.length(); c++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < keypad[j].length(); k++) {
					if (inp[c] == keypad[j][k]) {
						char a = outp[outp.length() - 1];
						int last = a - '0';
						if (j == last) {
							outp += " ";
						}
						stringstream pad;
						pad << j;
						if (k == 0) {
							outp += pad.str();
						}
						if (k == 1) {
							outp += pad.str() + pad.str();
						}
						if (k == 2) {
							outp += pad.str() + pad.str() + pad.str();
						}
						if (k == 3) {
							outp += pad.str() + pad.str() + pad.str() + pad.str();
						}
					}
				}
			}
		}
		cout << outp << endl;
	}
    return 0;
}
