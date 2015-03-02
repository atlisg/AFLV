#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

vector<int> adj[10000];
vector<bool> visited(10000, false);
int counter = 0;

void dfs(int u) {
	if (visited[u]) {
		return;
	}
	
	visited[u] = true;
	counter++;
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs(v);
	}
}

int main () {
	int tCases;
	cin >> tCases;
	
	for (int i = 0; i < tCases; i++) {
		
		int nDoms, nEdges, nStarts;
		cin >> nDoms >> nEdges >> nStarts;
		
		for (int j = 0; j < nEdges; j++) {
			int dom1, dom2;
			cin >> dom1 >> dom2;
			
			dom1--;
			dom2--;
			
			adj[dom1].push_back(dom2);
		}
		
		int starts[nStarts];
		for (int j = 0; j < nStarts; j++) {
			int sDom;
			cin >> sDom;
			
			sDom--;
			
			starts[j] = sDom;
		}
		
		for (int j = 0; j < nStarts; j++) {
			dfs(starts[j]);
		}
		
		cout << counter << endl;
		
		counter = 0;
		for (int j = 0; j < 10000; j++) {
			adj[j].clear();
			visited[j] = false;
		}
		
	}
    return 0;
}
