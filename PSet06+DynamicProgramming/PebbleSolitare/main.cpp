#include <iostream>
#include <map>
using namespace std;

map<string, int> mem;
int COUNTER = 23;

int move(string s) {
	
	if (mem.find(s) != mem.end()) {
		return mem[s];
	}
	
	// förum í öll möguleg move
	for (int i = 0; i < 22; i++) {
		
		// er move í spilunum
		if (s.substr(i, 2) == "oo") {
			
			// getum við farið til vinstri?
			if (i != 0) {
				if (s[i - 1] == '-') {
					string left = s;
					left[i]     = '-';
					left[i + 1] = '-';
					left[i - 1] = 'o';
					
					move(left);
				}
			}
			
			// getum við farið til hægri?
			if (i != 21) {
				if (s[i + 2] == '-') {
					string right = s;
					right[i]     = '-';
					right[i + 1] = '-';
					right[i + 2] = 'o';
					
					move(right);
				}
			}
		}
	}
	
	// teljum plebba
	int counter = 0;
	for (int i = 0; i < 23; i++) {
		if (s[i] == 'o') {
			counter++;
		}
	}
	
	// stillum global teljarann á nýtt gildi ef það er minna
	COUNTER = min(COUNTER, counter);

	mem[s] = COUNTER;
	
	return COUNTER;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		
		string inp;
		cin >> inp;
		
		cout << move(inp) << endl;
		
		COUNTER = 23;
	}
	
    return 0;
}
