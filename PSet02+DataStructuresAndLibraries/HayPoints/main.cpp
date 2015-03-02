#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

int main () {
	int n, m;
	scanf("%d", &m);
	scanf("%d", &n);
	
	map<string,int> dict;
	
	// insertum í orðabókina
	for (int i = 0; i < m; i++) {
		char word[30];
		int dollar;
		scanf("%s", word);
		scanf("%d", &dollar);
		dict.insert(pair<string,int>(word,dollar));
	}
	
	// insertum í starfslýsinguna
	for (int i = 0; i < n; i++) {
		string desc = "";
		char word[30];
		scanf("%s", word);
		while (word != ".") {
			desc += word + ' ';
			scanf("%s", word);
		}
		stringstream ss(desc);
		vector<string> descVec;
		string tmp;
		while (ss.good()) {
			ss >> tmp;
			descVec.push_back(tmp);
		}
		descVec.pop_back();

		// og finnum summu gilda orðanna í starfslýsingunni
		int sum = 0;
		for (int i = 0; i < descVec.size(); i++) {
			map<string,int>::iterator it = dict.find(descVec[i]);
			if (it != dict.end()) {
				int dollars = it->second;
				sum += dollars;
			}
		}
		printf("%d\n", sum);
	}
	
    return 0;
}
