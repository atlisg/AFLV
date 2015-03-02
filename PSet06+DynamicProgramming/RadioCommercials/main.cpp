#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int arr[100000];
int mem[100000];
bool comp[100000];

int max_sum(int i) {
	if (i == 0) {
		return arr[i];
	}
	if (comp[i]) {
		return mem[i];
	}
	
	int res = max(arr[i], arr[i] + max_sum(i - 1));
	
	mem[i] = res;
	comp[i] = true;
	
	return res;
}

int main() {
	memset(comp, 0, sizeof(comp));
	memset(mem, -1, sizeof(mem));
	int N, P;
	cin >> N >> P;
	
	for (int i = 0; i < N; i++) {
		int nStudents;
		cin >> nStudents;
		arr[i] = nStudents - P;
	}
	
/*	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
*/	
	int maximum = 0;
	for (int i = 0; i < N; i++) {
		maximum = max(maximum, max_sum(i));
	}
	printf("%d\n", maximum);
	
    return 0;
}
