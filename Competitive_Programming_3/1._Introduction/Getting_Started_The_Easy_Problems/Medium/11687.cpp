//2020-01-05 Digits by Mutska

#include <iostream>
#include <string> 

using namespace std;
int main(){


	string digit, temp;

	while(true){
		int i = 1;
		cin >> digit;
		if(digit == "END")
			break;
		temp = to_string(digit.size());
		while(1){
		if(temp == digit){
			cout << i << "\n";
			break;
		}
		i++;
		digit = temp;
		temp = to_string(digit.size());
		
		}
	}


	return 0;
}
