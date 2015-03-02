#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

vector<pair<int, int> > adj[1100][1100];
bool visited[1100][1100];
string sMap[1100];
int coastLength = 0;

void countCoastDFS(int u, int v) {

	if (visited[u][v]) {
		return;
	}
	
	visited[u][v] = true;
	
	for (int i = 0; i < adj[u][v].size(); i++) {
		pair<int, int> w = adj[u][v][i];
		
		if (sMap[w.first][w.second] == '0') {
			countCoastDFS(w.first, w.second);
		}
		else {
			coastLength++;
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	
	memset(visited, 0, sizeof(visited));
	
	string zeros = "";
	for (int i = 0; i < M + 2; i++) {
		zeros += "0";
	}
	sMap[0] = sMap[N + 1] = zeros;

	for (int i = 1; i <= N; i++) {
		string inp;
		cin >> inp;
		sMap[i] = inp;
	}
	
	for (int i = 1; i < N + 1; i++) {
		sMap[i] = "0" + sMap[i] + "0";
	}
	
	// Tengi saman alla reitina
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			if (i > 0) {
				adj[i][j].push_back(pair<int, int>(i - 1, j));
				adj[i - 1][j].push_back(pair<int, int>(i, j));
			}
			if (j > 0) {
				adj[i][j].push_back(pair<int, int>(i, j - 1));
				adj[i][j - 1].push_back(pair<int, int>(i, j));
			}
		}
	}
	
	countCoastDFS(0, 0);
	
	cout << coastLength << endl;
		
    return 0;
}
