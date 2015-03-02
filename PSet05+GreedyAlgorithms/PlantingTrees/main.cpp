#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main () {
	int N;
	cin >> N;
	int seeds[N];
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		seeds[i] = t;
	}
	
	sort(seeds, seeds + N, greater<int>());
	
	int maxInt = 0;
	
	for (int i = 0; i < N; i++) {
		seeds[i] -= (N - i);
		if (seeds[i] > maxInt) {
			maxInt = seeds[i];
		}
	}

	cout << N + maxInt + 2 << endl;
	
    return 0;
}
