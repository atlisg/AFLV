#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

vector<double> dist(10001, 0.0);

struct edge {
	int u, v;
	double weight;
	
	edge(int _u, int _v, double _w) {
		u = _u;
		v = _v;
		weight = _w;
	}
};

vector<edge> adj[10001];

void dijkstra(int start) {
	dist[start] = 1.0;
	priority_queue<pair<int, int>,
	vector<pair<int, int> >,
	greater<pair<int, int> > > pq;
	pq.push(make_pair(dist[start], start));
	
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].v;
			double w = adj[u][i].weight;
			
			if (w * dist[u] > dist[v]) {
				dist[v] = w * dist[u];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main() {
	
	int N, M;
	scanf("%d %d", &N, &M);
	
	while (N != 0 && M != 0) {
		
		for (int i = 0; i < M; i++) {
			int x, y;
			double f;
			cin >> x >> y >> f;
			
			adj[x].push_back(edge(x, y, f));
			adj[y].push_back(edge(y, x, f));
		}
		
		dijkstra(0);
		
		cout << fixed << setprecision(4) << dist[N - 1] << endl;
		
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			dist[i] = 0.0;
		}
		
		scanf("%d %d", &N, &M);
		
	}
	
    return 0;
}
