#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct flow_network {
	
    struct edge {
        int u, v;
		int cap;
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
            int u = Q.front(); Q.pop();
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
		
        return flow;
    }
};

int main() {
	
	int T;
	cin >> T;
	
    while (T > 0) {
		
		int c, d, v;
		cin >> c >> d >> v;
		
		vector<pair<string, string> > dogLovers;
		vector<pair<string, string> > catLovers;
		
		for (int i = 0; i < v; i++) {
			string voteIn;
			string voteOff;
			cin >> voteIn >> voteOff;

			if (voteIn[0] == 'D') {
				dogLovers.push_back(pair<string, string>(voteIn, voteOff));
			}
			else {
				catLovers.push_back(pair<string, string>(voteIn, voteOff));
			}
		}

		int SOURCE = 0,
        SINK = 1,
        LEFT = 2,
        RIGHT = LEFT + dogLovers.size(),
        CNT = RIGHT + catLovers.size();
		
        flow_network g(CNT);
		
		bool edges[CNT][CNT];
		for (int i = 0; i < CNT; i++) {
			for (int j = 0; j < CNT; j++) {
				edges[i][j] = false;
			}
		}
		
        for (int i = 0; i < dogLovers.size(); i++) {
			for (int j = 0; j < catLovers.size(); j++) {
				if (dogLovers[i].first == catLovers[j].second || dogLovers[i].second == catLovers[j].first) {
					if (!edges[LEFT + i][RIGHT + j]) {
						g.add_edge(LEFT + i, RIGHT + j, 1);
						edges[LEFT + i][RIGHT + j] = true;
					}
					if (!edges[SOURCE][LEFT + i]) {
						g.add_edge(SOURCE, LEFT + i, 1);
						edges[SOURCE][LEFT + i] = true;
					}
					if (!edges[RIGHT + j][SINK]) {
						g.add_edge(RIGHT + j, SINK, 1);
						edges[RIGHT + j][SINK] = true;
					}
				}
			}
        }
		
        cout << v - g.max_flow(SOURCE, SINK) << endl;
		
		T--;
    }
	
    return 0;
}

