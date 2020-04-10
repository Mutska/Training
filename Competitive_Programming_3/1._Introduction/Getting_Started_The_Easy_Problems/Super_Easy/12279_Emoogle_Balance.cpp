//2019-12-30 Emoogle Balance by Mutska

#include <iostream>

using namespace std;

int main(){
	

	int N, emogle_balance, event, count = 1;

	while(1){
		cin >> N;
		if(N == 0)
			break;
		emogle_balance = 0;
		while(N--){
			cin >> event;
			if(event == 0)
				emogle_balance--;
			else
				emogle_balance++;
		
		}

		cout << "Case " << count << ": " << emogle_balance << "\n";
		count++;
	
	
	
	}


	return 0;
}
