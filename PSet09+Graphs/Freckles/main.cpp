#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

pair<double, double> freckles[1000];

struct edge {
	int u, v;
	double weight;
	edge(int _u, int _v, double _w) {
		u = _u;
		v = _v;
		weight = _w;
	}
};

struct union_find {
	vector<int> parent;
	union_find(int n) {
		parent = vector<int>(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		if (parent[x] == x) {
			return x;
		} else {
			parent[x] = find(parent[x]);
			return parent[x];
		}
	}
	void unite(int x, int y) {
		parent[find(x)] = find(y);
	}
};

bool edge_cmp(const edge &a, const edge &b) {
	return a.weight < b.weight;
}

vector<edge> mst(int n, vector<edge> edges) {
	
	union_find uf(n);
	sort(edges.begin(), edges.end(), edge_cmp);
	
	vector<edge> res;
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].u,
			v = edges[i].v;
		
		if (uf.find(u) != uf.find(v)) {
			uf.unite(u, v);
			res.push_back(edges[i]);
		}
	}
	
	return res;
}

int main() {
	
	int testCases;
	scanf("%d", &testCases);
	
	for (int t = 0; t < testCases; t++) {
		
		scanf("\n");
		
		int N;
		scanf("%d", &N);
		
		vector<edge> adj;
		
		for (int i = 0; i < N; i++) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			
			freckles[i] = pair<double, double>(x, y);
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				double weight = sqrt((freckles[i].first  - freckles[j].first)  * (freckles[i].first  - freckles[j].first) 
								   + (freckles[i].second - freckles[j].second) * (freckles[i].second - freckles[j].second));
				adj.push_back(edge(i, j, weight));
			}
		}
		
		vector<edge> minSP = mst(N, adj);
		
		double total = 0.0;
		for (int i = 0; i < minSP.size(); i++) {
			total += minSP[i].weight;
		}
		
		cout << fixed << setprecision(2) << total << endl << endl;
		
	}
	
    return 0;
}
