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

struct union_find {
	map<string, int> myMap;
	vector<int> parent;
	vector<int> nFriends;
	union_find(int n) {
		parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
		nFriends = vector<int>(n);
		for (int i = 0; i < n; i++) {
			nFriends[i] = 1;
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
	
    void unite(int n, string p1, string p2) {
		map<string, int>::iterator it1 = myMap.find(p1);
		map<string, int>::iterator it2 = myMap.find(p2);
		
		if (it1 != myMap.end() && it2 != myMap.end()) {
			int tempo1 = find(it1->second);
			int tempo2 = find(it2->second);
			if (tempo1 == tempo2) {
				return;
			}
			parent[tempo1] = tempo2;
			nFriends[tempo2] += nFriends[tempo1];
			nFriends[tempo1] = nFriends[tempo2];
			it1->second = it2->second;
		}
		else if (it1 == myMap.end() && it2 == myMap.end()) {
			myMap.insert(pair<string, int>(p1, n + 1));
			myMap.insert(pair<string, int>(p2, n + 1));
			parent[n] = n + 1;
			nFriends[n + 1] += nFriends[n];
			nFriends[n] = nFriends[n + 1];
		} 
		else if (it1 == myMap.end()) {
			int tempo2 = find(it2->second);
			myMap.insert(pair<string, int>(p1, tempo2));
			parent[n] = tempo2;
			nFriends[n] += nFriends[tempo2];
			nFriends[tempo2] = nFriends[n];
		} 
		else if (it2 == myMap.end()) {
			int tempo1 = find(it1->second);
			myMap.insert(pair<string, int>(p2, tempo1));
			parent[n + 1] = tempo1;
			nFriends[n + 1] += nFriends[tempo1];
			nFriends[tempo1] = nFriends[n + 1];
		}
    }
	
	int sum(string p1) {
		map<string, int>::iterator it = myMap.find(p1);
		return nFriends[find(it->second)];
	}
};

int main () {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int F;
		cin >> F;
		union_find uf(F * 2);
		for (int j= 0; j < F; j++) {
			string p1, p2;
			cin >> p1 >> p2;
			uf.unite(j * 2, p1, p2);
			cout << uf.sum(p1) << endl;
		}
	}
    return 0;
}
