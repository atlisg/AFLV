#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

struct node {
	char c;
	node* children[26];
	bool is_end;
	int counter;
	node(char letter) {
		c = letter;
		memset(children, 0, sizeof(children));
		is_end = false;
		counter = 1;
	}
};

int main() {
	
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	string s;
	getline(cin, s);
	
	while (s != ".") {
		
		node* trie = new node(s[0]);
		node* runner = trie;
		
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == trie->c) {
				runner = trie;
				runner->counter++;
			}
			else if (runner->children[s[i] - 'a'] == NULL) {
				runner->children[s[i] - 'a'] = new node(s[i]);
				runner = runner->children[s[i] - 'a'];
			}
			else {
				runner->children[s[i] - 'a']->counter++;
				runner = runner->children[s[i] - 'a'];
			}
		}
		
		cout << runner->counter << endl;
		
		getline(cin, s);
	}
	
    return 0;
}
