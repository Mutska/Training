//2020-01-06 Reverse and Add by Mutska

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

	string initial, temporal;
	int T, count;
   	long long int result;
	cin >> T;
	
	while(T--){
		cin >> initial;
		temporal = initial;
		reverse(initial.begin(), initial.end());
		result = stoll(temporal) + stoll(initial);
		count = 1;
		while(1){
			temporal = to_string(result);
			initial  = temporal;
			reverse(temporal.begin(), temporal.end());
			if(initial == temporal){
				cout << count << " " << initial << "\n";
				break;
			}
			result = stoll(temporal) + stoll(initial);
			count++;

		}
				
	
	}




	return 0;
}
