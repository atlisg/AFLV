#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main () {
	while (!cin.eof()) {
		char c = cin.peek();
		cin.ignore(1);
		if (cin.peek() == EOF) {
			break;
		}
		cin.putback(c);
		stack<int> myStack;
		queue<int> myQueue;
		priority_queue<int> myPQ;
		
		bool possible = true;
		bool canBeStack = true;
		bool canBeQueue = true;
		bool canBePQ = true;
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int iType, x;
			cin >> iType >> x;
			if (iType == 1) {
				myStack.push(x);
				myQueue.push(x);
				myPQ.push(x);
			} else {
				if (myStack.empty()) {
					possible = false;
					continue;
				}
				if (x != myStack.top()) {
					canBeStack = false;
				}
				if (x != myQueue.front()) {
					canBeQueue = false;
				}
				if (x != myPQ.top()) {
					canBePQ = false;
				}
				myStack.pop();
				myQueue.pop();
				myPQ.pop();
			}
		}
		if (!possible || (canBeStack + canBeQueue + canBePQ == 0)) {
			cout << "impossible\n";
		} else if (canBeStack + canBeQueue + canBePQ > 1) {
			cout << "not sure\n";
		} else if (canBeStack) {
			cout << "stack\n";
		} else if (canBeQueue) {
			cout << "queue\n";
		} else if (canBePQ) {
			cout << "priority queue\n";
		}
	}
    return 0;
}
