//2019-12-30 Save Shetu by Mutska

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	
	string input;
	int T, total = 0;
	
	cin >> T;
	cin.ignore();

	while(T--){
		getline(cin, input);
		if(input == "report")
			cout << total << "\n";
		else{
			total += stoi(input.substr(7, input.size()-1));
		}
	}




	return 0;
}
