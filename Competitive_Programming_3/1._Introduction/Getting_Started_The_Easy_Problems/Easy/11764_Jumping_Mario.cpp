//2019-01-01 Jumping Mario by Mutska
#include <iostream>

using namespace std;

int main(){

	int T, N, wall, low_jumps, high_jumps, temp, count = 1;
		
	cin >> T;

	while(T--){
		cin >> N;
		low_jumps = 0;
		high_jumps = 0;
		if(N == 0){
			cout << "Case " << count << ": " << high_jumps << " " << low_jumps <<"\n";
			count++;
			continue;
		}
		if(N == 1){
			cin >> wall;
			cout << "Case " << count << ": " << high_jumps << " " << low_jumps <<"\n";
			count++;
			continue;
		}
		cin >> wall;
		temp = wall;
		N--;
		while(N--){
			cin >> wall;
			if(wall > temp)
				high_jumps++;
			else if (wall  < temp)
				low_jumps++;
			temp = wall;
		}
		cout << "Case " << count <<  ": " << high_jumps << " " << low_jumps << "\n";
		count++;
	
	}


	return 0;
}


