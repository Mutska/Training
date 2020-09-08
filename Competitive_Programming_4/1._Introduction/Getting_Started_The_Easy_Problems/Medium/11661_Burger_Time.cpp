//2020-01-04 Burger Time?

#include <iostream>
#include <algorithm> 
using namespace std;


int main(){

	int L;
	int minimum;
	string highway;
	int D, R;
	while(cin >> L){
		if(L == 0)
			break;
		cin >> highway;
		int size = highway.size();
		D = R = -1;
		minimum = 2000000;
		for(int i = 0; i < size; i++){
			if(highway[i] == 'Z'){
				minimum = 0;
				break;
			}	
			if(highway[i] == 'D')
				D = i;		
			if(highway[i] == 'R')
				R = i;
			if(D >= 0 && R >= 0){
				minimum = min(minimum, abs(D-R));
			}	
				
		}
		cout << minimum << "\n";
	
	}


	return 0;
}
