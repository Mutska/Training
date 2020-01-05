//2020-01-04 Train Tracks by Mutska
#include <iostream>

using namespace std;


int main(){

	string line_tracks;
	int T;
	int F, M;

	cin >> T;
	cin.ignore();

	while(T--){
		F = M = 0;
		getline(cin, line_tracks);

		for(auto a: line_tracks){
			if(a == 'F')
				F++;
			if(a == 'M')
				M++;
		}
		if(F == M && F > 1)
			cout << "LOOP\n";
	   	else
			cout << "NO LOOP\n";	

	
	}




	return 0;
}
