//2020-01-07 Mother bear by Mutska

#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

	string input, original;

	while(1){
		getline(cin, input);
		if(input == "DONE")
			break;
		input.erase(remove(input.begin(), input.end(),'.'), input.end());
		input.erase(remove(input.begin(), input.end(),','), input.end());
		input.erase(remove(input.begin(), input.end(),'?'), input.end());
		input.erase(remove(input.begin(), input.end(),'!'), input.end());
		input.erase(remove(input.begin(), input.end(),' '), input.end());
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		original = input;
		reverse(input.begin(), input.end());
		if(original == input)
			cout << "You won't be eaten!\n";
		else
			cout << "Uh oh..\n";
	
	}

	return 0;
}
