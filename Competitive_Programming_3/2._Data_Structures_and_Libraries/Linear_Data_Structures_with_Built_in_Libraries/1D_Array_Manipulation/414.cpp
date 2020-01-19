//2020-01-14 Machined Surfaces by Mutska
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, count, blanks;
	string line;
	vector<int> spaces;
	while(cin >> N) {
		if(N == 0) break;
		cin.ignore();
		spaces.clear();
		while(N--){
			count = 0;	
			getline(cin, line);
			for(char c: line)
			   	(c == 'X') ? count++ : count += 0;
			spaces.emplace_back(25 - count);
		}
		sort(spaces.begin(), spaces.end());
		blanks = 0;
		for(int i = 1; i < (int) spaces.size(); i++)
			blanks += spaces[i] - spaces[0];
		cout << blanks << "\n";
	}


	return 0;
}
