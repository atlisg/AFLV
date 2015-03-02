#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct flow_network {
	
    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
		: u(_u), v(_v), cap(_cap), forward(forw) { }
    };
	
    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }
	
    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }
	
    int augment(int s, int t) {
        vector<edge*> back(n, NULL);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); 
			Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }
		
        if (back[t] == NULL)
            return 0;
		
        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }
		
        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }
		
        return bneck;
    }
	
    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }
			
            flow += f;
        }
		
		vector<edge*> edges;
		
		for (int i = 0; i < adj.size(); i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				if (!adj[i][j]->forward && adj[i][j]->cap != 0) {
					edges.push_back(adj[i][j]);
				}
			}
		}
		int eSize = edges.size();
		printf("%d %d %d\n", n, flow, eSize);
		
		for (int i = 0; i < eSize; i++) {
			printf("%d %d %d\n", edges[i]->v, edges[i]->u, edges[i]->cap);
		}
		
        return flow;
    }
};

int main() {
	
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	
	flow_network flo(n);
	
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		flo.add_edge(u, v, c);
	}
	
	flo.max_flow(s, t);
	
    return 0;
}
