//2019-12-32 Hajj-e-Akbar by Mutska

#include <iostream>
#include <string>

using namespace std;

int main(){

	string input;
	int count = 1;

	while(cin >> input){
		if(input == "Hajj")
			cout << "Case " << count << ": " << "Hajj-e-Akbar" << "\n";
		else if(input == "Umrah")
			cout << "Case " << count << ": " << "Hajj-e-Asghar" << "\n";
		else
			break;
		count++;
	}




	return 0;
}
