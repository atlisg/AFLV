#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>
#include <cassert>
using namespace std;

const int ALPHABET_SIZE = 10;

struct TrieNode {
    TrieNode(bool present = false);
    bool is_leaf();
	
    bool present;
    TrieNode* children[ALPHABET_SIZE];
};

typedef TrieNode* NodePtr;

int get_index(char c) {
    int ind = tolower(c) - '0';
    assert(0 <= ind && ind < ALPHABET_SIZE);
    return ind;
}

TrieNode::TrieNode(bool present) {
    this->present = present;
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = NULL;
    }
}

bool TrieNode::is_leaf() {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(children[i] != NULL) {
            return false;
        }
    }
    return true;
}

class PrefixStringSet {
public:
	PrefixStringSet();
	bool insert(string s);
	bool contains(string s);
	
private:
	NodePtr root;
};

PrefixStringSet::PrefixStringSet() {
    root = new TrieNode();
}

bool PrefixStringSet::contains(string s) {
	NodePtr runner = root;
	for (int i = 0; s[i] != '\0'; i++) {
		if (runner->children[get_index(s[i])] == NULL) {
			return false;
		}
		runner = runner->children[get_index(s[i])];
	}
	return true;
}

bool PrefixStringSet::insert(string s) {
	if (contains(s)) {
		return true;
	}
	NodePtr runner = root;
	for (int i = 0; s[i] != '\0'; i++) {
		char digit = s[i];
		if (runner->children[get_index(digit)] == NULL) {
			if (s[i + 1] == '\0') {
				runner->children[get_index(digit)] = new TrieNode(true);
				return false;
			}
			runner->children[get_index(digit)] = new TrieNode;
			runner = runner->children[get_index(digit)];
		} else {
			runner = runner->children[get_index(digit)];
			if (runner->present) {
				return true;
			}
		}
	}
	return false;
}


int main () {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		PrefixStringSet myPSS;
		bool preFix = false;
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string inp;
			cin >> inp;
			if (myPSS.insert(inp)) {
				preFix = true;
			}
		}
		if (preFix) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
    return 0;
}
