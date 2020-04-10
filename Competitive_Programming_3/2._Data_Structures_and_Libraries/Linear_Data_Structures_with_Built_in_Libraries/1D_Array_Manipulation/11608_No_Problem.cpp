//2020-01-15 No Problem by Mutska

#include <iostream>
#include <array> 

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	array<int , 12> created;
	array<int , 12> required;
	array<int , 12> available;
	int S, n, count = 1;
	while(cin >> S){
		if(S < 0) break;
		cout << "Case " << count++ << ":\n";
		for(int i = 0; i < 12; i++ ) {
			cin >> n;
			created[i] = n;
		}
		for(int i = 0; i < 12; i++)	 {
			cin >> n;
			required[i] = n;	
		}
		available[0] = S;
		for(int i = 0; i < 12; i++){
			if(i + 1 != 12)
				available[i + 1] = created[i];
		}
		for(int i = 0; i < 12; i++){
			if(available[i] < required[i]){
				cout << "No problem. :(\n";
			}else{
				cout << "No problem! :D\n";
					available[i] -= required[i];
			}
			if(i + 1 != 12)
				available[i+1] += available[i];
		}
	
	}


	return 0;
}
