#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[20000];
vector<int> invAdj[20000];
vector<int> low(20000), num(20000, -1);
vector<bool> incomp(20000, false);
vector<int> component(20000);
vector<bool> noIns(20000, true);
vector<bool> noOuts(20000, true);
int curnum = 0;
int components = 0;
stack<int> comp;


void scc(int u) {
	
	comp.push(u);
	incomp[u] = true;
	
	low[u] = num[u] = curnum++;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (num[v] == -1) {
			scc(v);
			low[u] = min(low[u], low[v]);
		} else if (incomp[v]) {
			low[u] = min(low[u], num[v]);
		}
	}
	
	if (num[u] == low[u]) {

		while (true) {
			int cur = comp.top();
			comp.pop();
			incomp[cur] = false;

			component[cur] = components;
			if (cur == u) {
				break;
			}
		}
		components++;
	}
}

int main() {
	
	int T;
	cin >> T;
	
	while (T > 0) {
		
		curnum     = 0;
        components = 0;
        num.assign(20000, -1);
		component.clear();
		
		int n, m;
		cin >> n >> m;
		
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			
			adj[a].push_back(b);
			invAdj[b].push_back(a);
		}
		
		for (int i = 0; i < n; i++) {
			if (num[i] == -1) {
				scc(i);
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < invAdj[i].size(); k++) {
				if (component[invAdj[i][k]] != component[i]) {
					noIns[component[i]] = false;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < adj[i].size(); k++) {
				if (component[adj[i][k]] != component[i]) {
					noOuts[component[i]] = false;
				}
			}
		}
		
		int cntNoOuts = 0;
		int cntNoIns  = 0;
		
		for (int i = 0; i < components; i++) {
			if (noOuts[i]) {
				cntNoOuts++;
			}
			if (noIns[i]) {
				cntNoIns++;
			}
		}
		
		if (components == 1) {
			cout << 0 << endl;
		}
		else {
			cout << max(cntNoIns, cntNoOuts) << endl;
		}
		
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			invAdj[i].clear();
			incomp[i] = false;
			noOuts[i] = true;
			noIns[i] = true;
		}
		
		T--;
	}
	
    return 0;
}
