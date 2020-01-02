//2019-01-01 Horror Dash by mutwska

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int T, N, a, count = 1;
	vector<int> speeds;

	cin >> T;
	
	while(T--){
		cin >> N;
		while(N--){
			cin >> a;
			speeds.push_back(a);
		}
		sort(speeds.rbegin(), speeds.rend());
		cout << "Case " << count << ": " << speeds[0] << "\n";
		count++;
		speeds.clear();
	
	}


	return 0;
}
