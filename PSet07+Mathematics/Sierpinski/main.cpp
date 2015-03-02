#include <iostream>
#include <cmath>
using namespace std;

int lengthOfNum(int n) {
	return floor((((n + 1) * log10(3.0)) - (n * log10(2))) + 1);
}

int main () {
	int n;
	cin >> n;
	for (int i = 1; cin.good(); i++) {
		
		cout << "Case " << i << ": " << lengthOfNum(n) << "\n";
		
		cin >> n;
	}
	
    return 0;
}
