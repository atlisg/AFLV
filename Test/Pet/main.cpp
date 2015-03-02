#include <iostream>
using namespace std;

int main() {
	
	int arr[5];
	
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		int inp;
		for (int j = 0; j < 4; j++) {
			cin >> inp;
			sum += inp;
		}
		arr[i] = sum;
	}
	
	int maxI = 0;
	int ind = 0;
	for (int i = 0; i < 5; i++) {
		if (maxI < arr[i]) {
			maxI = arr[i];
			ind = i + 1;
		}
	}
	
	cout << ind << " " << maxI;
	
    return 0;
}
