//2019-12-30 One-Two-Three by Mutska

#include <iostream>
#include <string> 

using namespace std;

int main(){

	string number;
	int T;

	cin >> T;

	while(T--){
		cin >> number;
		if(number.length() > 3)
			cout << 3 << "\n";
		else if((number[1] == 'w' && number[2] == 'o') || (number[0] == 't' && number[2] == 'o') ||   (number[0] == 't' && number[1] == 'w'))
			cout << 2 << "\n";
		else
			cout << 1 << "\n";
	
	}



	return 0;
}
