#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct node {
	int x;
	int y;
	bool visited;
	node(int a, int b) {
		x = a;
		y = b;
		visited = false;
	}
};
typedef node* NodePtr;

bool happy(vector<NodePtr> stores, NodePtr curr, NodePtr last) {
	curr->visited = true;
	int length = abs(curr->x - last->x) + abs(curr->y - last->y);
	if (length <= 1000) {
		return true;
	}
	for (int i = 1; i < stores.size() - 1; i++) {
		int currLength = abs(curr->x - stores[i]->x) + abs(curr->y - stores[i]->y);
		if (!stores[i]->visited && currLength <= 1000) {
			if (happy(stores, stores[i], last)) {
				return true;
			}
		}
	}
	return false;
}

int main () {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		vector<NodePtr> vec;
		vec = vector<NodePtr>(n + 2);
		
		int x, y;
		for (int j = 0; j < n + 2; j++) {
			cin >> x >> y;
			vec[j] = new node(x, y);
		}
		
		if (happy(vec, vec[0], vec[vec.size() - 1])) {
			cout << "happy\n";
		} else {
			cout << "sad\n";
		}
	}
    return 0;
}
