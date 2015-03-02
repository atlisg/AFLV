#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main () {
	int N, M;
	scanf("%d",&N);
	scanf("%d",&M);
	
	while (N != 0 && M != 0) {
		int catalogNr;
		int cnt = 0;
		
		vector<int> Jack;
		
		for (int i = 0; i < N; i++) {
			scanf("%d",&catalogNr);
			Jack.push_back(catalogNr);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d",&catalogNr);
			if (binary_search(Jack.begin(), Jack.end(), catalogNr)) {
				cnt++;
			}
		}
		printf("%d\n",cnt);
		scanf("%d",&N);
		scanf("%d",&M);
	}
    return 0;
}
