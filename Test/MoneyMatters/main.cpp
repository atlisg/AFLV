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

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo


struct union_find {
    vector<pair<int, int> > parent;
    union_find(int n) {
        parent = vector<pair<int, int> >(n);
        for (int i = 0; i < n; i++) {
            parent[i].first = i;
			parent[i].second = 0;
        }
    }
    int find(int x) {
        if (parent[x].first == x) {
            return x;
        } else {
            parent[x].first = find(parent[x].first);
            return parent[x].first;
        }
    }
    void unite(int x, int y) {
        parent[find(x)].first = find(y);
    }
};


int main() {
	
	int n, m;
	cin >> n >> m;
	
	union_find uf(n);
	
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;
		uf.parent[i].second = inp;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		uf.unite(a, b);
	}
	
	int sum[n];
	
	for (int i = 0; i < n; i++) {
		sum[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (uf.find(i) == uf.find(j)) {
				sum[i] += uf.parent[j].second;
			}
		}
	}
	
	bool yes = true;
	for (int i = 0; i < n; i++) {
		if (sum[i] != 0) {
			yes = false;
		}
	}
	
	if (yes) {
		cout << "POSSIBLE" << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}

	
    return 0;
}










