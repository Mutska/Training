//2019-01-01 Lumberjack Sequencing by Mutska

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int N, a;
	vector<int> lumberjacks;
	cout << "Lumberjacks:\n";
	cin >> N;
	while(N--){
		int ten = 10;
		while(ten--){
			cin >> a;
			lumberjacks.push_back(a);
		}
		if(is_sorted(lumberjacks.rbegin(), lumberjacks.rend()) || is_sorted(lumberjacks.begin(), lumberjacks.end()))
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
			
		lumberjacks.clear();

	}
	


	return 0;
}
