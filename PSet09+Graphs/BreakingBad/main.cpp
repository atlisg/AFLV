#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> sItems;
map<int, string> iItems;

vector<pair<string, int> > adj[100000];
vector<int> side(100000, -1);
bool is_bipartite = true;

vector<string> walter;
vector<string> jesse;

void check_bipartite(int u) {
	for (int i = 0; i < adj[u].size(); i++) {
		pair<string, int> v = adj[u][i];
		if (side[v.second] == -1) {
			side[v.second] = 1 - side[u];
			check_bipartite(v.second);
		} else if (side[u] == side[v.second]) {
			is_bipartite = false;
		}
	}
}

int main() {
	
	int N, M;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string item;
		cin >> item;
		sItems.insert(pair<string, int>(item, i));
		iItems.insert(pair<int, string>(i, item));
	}
	
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		string item1, item2;
		cin >> item1 >> item2;
		
		int iIt1 = sItems[item1];
		int iIt2 = sItems[item2];
		
		adj[iIt1].push_back(pair<string, int>(item2, iIt2));
		adj[iIt2].push_back(pair<string, int>(item1, iIt1));
	}
	
	for (int u = 0; u < N; u++) {
		if (side[u] == -1) {
			side[u] = 0;
			check_bipartite(u);
		}
		if (1 - side[u] == 0) {
			walter.push_back(iItems[u]);
		}
		else {
			jesse.push_back(iItems[u]);
		}
	}
	
	if (is_bipartite) {
		for (int i = 0; i < walter.size(); i++) {
			cout << walter[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < jesse.size(); i++) {
			cout << jesse[i] << " ";
		}
		cout << endl;
	}
	
	else {
		cout << "impossible" << endl;
	}

	
    return 0;
}
