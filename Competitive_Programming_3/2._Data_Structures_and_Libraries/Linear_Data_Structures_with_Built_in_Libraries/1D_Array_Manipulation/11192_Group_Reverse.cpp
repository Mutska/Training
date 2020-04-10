//2020-01-15 Group Reverse by Mutska

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int N, init, end, group;
	string line;
	while(cin >> N, (N || false)){
		cin.ignore();
		getline(cin, line);
		group =  (int) line.size() / N;
		init = 0; end = group;
		while(end <= (int) line.size()){
			reverse(line.begin() + init, line.begin() + end);
			init += group;
			end += group;
		}
		cout << line << "\n";	
		
	
	}




	return 0;
}
