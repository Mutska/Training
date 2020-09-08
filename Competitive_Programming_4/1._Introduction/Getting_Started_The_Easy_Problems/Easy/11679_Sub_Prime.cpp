//2019-01-01 Sub-Prime by Mutska

#include <iostream>
#include <map>

using namespace std;

int main(){
	

	int B, N, R, D, C, V, index, flag;
	map<int, int> banks;
	while(cin >> B >> N){
		if((B || N) == 0)
			break;
		index = 1;
		flag = true;
		while(B--){
			cin >> R;
			banks[index] = R;
			index++;
		}	
		while(N--){
			cin >> D >> C >> V;
			banks[D] -= V;
			banks[C] += V;
		}
		for(auto bank: banks){
			if(bank.second < 0){
				flag = false;
				break;
			}

		}
		if(flag)
			cout << "S\n";
		else
			cout << "N\n";
		banks.clear();
	
	
	}


	return 0;
}
