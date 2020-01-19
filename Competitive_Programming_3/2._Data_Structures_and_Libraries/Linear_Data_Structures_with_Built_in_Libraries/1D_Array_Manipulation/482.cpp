//2020-01-19 Permutation Arrays by Mutska
#include <iostream>
#include <cstdio>
#include <string>
#include <vector> 
#include <algorithm>
#include <sstream>
using namespace std;

int main() {

	int T, n;
	string line, str;
	vector<int> index;	
	vector<string> array;	
	vector<pair<int, string>> result;
	scanf("%d", &T);
	getchar();
	while(T--){
		index.clear();
		array.clear();
		result.clear();
		getchar();
		getline(cin, line);
		stringstream ss1(line);
		while(ss1 >> n) index.push_back(n);
		getline(cin, line);
		stringstream ss2(line);
		while(ss2 >> str) array.push_back(str);
		int minimum = min( array.size(), index.size());
		for(int i = 0; i < minimum; i++)
			result.push_back({ index[i], array[i]});	
		sort(result.begin(),result.end());
		for(int i = 0; i < minimum; i++)
			cout << result[i].second << "\n";
		if(T) printf("\n");

	}	
	return 0;
}
