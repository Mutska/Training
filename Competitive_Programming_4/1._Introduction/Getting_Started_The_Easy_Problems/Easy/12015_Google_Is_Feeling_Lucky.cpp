//2020-01-01 Google is Feeling Lucky by Mutska

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	
	vector<pair<int, string>> ranks;
	string web, data, rank;
	int T, numeric_rank, count = 1;;
	cin >> T;
	cin.ignore();
	while(T--){
		int ten = 10;
		while(ten--){
		getline(cin,data);
		int space = data.find_first_of(" ");
		web = data.substr(0, space);
		rank = data.substr(space + 1);
		numeric_rank = stoi(rank);
		ranks.push_back(make_pair(numeric_rank, web));
		}
		int max = 0;
		cout << "Case #" << count << ":\n";
		for(auto d: ranks){
			if(d.first >= max)
				max = d.first;
		}
		for(auto d: ranks){
			if(d.first == max)
				cout << d.second << "\n";
		}


		count++;
		ranks.clear();
	}



	return 0;
}
