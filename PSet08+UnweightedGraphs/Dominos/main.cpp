#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;

vector<int>         adj[110000];
vector<int>      invAdj[110000];
vector<int>         low(110000), num(110000, -1);
vector<bool>     incomp(110000, false);
vector<bool> infallable(110000, true);
vector<int>   component(110000);

int curnum     = 0;
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

int main () {
	int tCases;
	cin >> tCases;
	
	for (int i = 0; i < tCases; i++) {
		
		curnum     = 0;
        components = 0;
        num.assign(110000, -1);
		component.clear();
		
		int nDoms, nEdges;
		cin >> nDoms >> nEdges;
		
		for (int j = 0; j < nEdges; j++) {
			int dom1, dom2;
			cin >> dom1 >> dom2;
			
			dom1--;
			dom2--;
			
			adj[dom1].push_back(dom2);
			invAdj[dom2].push_back(dom1);
		}

		for (int s = 0; s < nDoms ; s++) {
			if (num[s] == -1) {
				scc(s);
			}
		}
		
		int cnt = 0;
		
		for (int j = 0; j < nDoms; j++) {
			for (int k = 0; k < invAdj[j].size(); k++) {
				if (component[invAdj[j][k]] != component[j]) {
					infallable[component[j]] = false;
				}
			}
		}
		
		for (int j = 0; j < components; j++) {
			if (infallable[j] == true) {
				cnt++;
			}
		}
		
		cout << cnt << endl;
		
		for (int j = 0; j < 110000; j++) {
			adj[j].clear();
			invAdj[j].clear();
			incomp[j]     = false;
			infallable[j] = true;
		}
		
	}
    return 0;
}
