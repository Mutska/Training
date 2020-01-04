//2020-01-03 Zeros and Ones by Mutska

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	char input[1000000];
	int count = 1, t, minium, maximum, temp, a, b;
	bool flag;
	while(cin >> input){
			cin >> t;
			cout << "Case " << count << ":\n";
			while(t--){
				cin >> a >> b;
				minium = min(a, b);
				maximum = max(a, b);
				flag = true;
				temp = input[minium];
				for(int i = minium; i <= maximum; i++){
					if(input[i] != temp)
						flag = false;
					temp = input[i];	
				
				}
				if(flag)
					cout << "Yes\n";
				else
					cout << "No\n";
			}	
			count++;
	}
	return 0;
}
