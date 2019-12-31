//2019-12-30 Language Detection by Mutska

#include <iostream>
#include <string>

using namespace std;

int main(){

	string hello;
	int count = 1;

	while(cin >> hello){
		
		if (hello == "HELLO")
			cout << "Case " << count << ": " << "ENGLISH" << "\n";
		else if (hello == "HOLA")
			cout << "Case " << count << ": " << "SPANISH" << "\n";
		else if (hello == "HALLO")
			cout << "Case " << count << ": " << "GERMAN" << "\n";
		else if (hello == "BONJOUR")
			cout << "Case " << count << ": " << "FRENCH" << "\n";
		else if (hello == "CIAO")
			cout << "Case " << count << ": " << "ITALIAN" << "\n";
		else if (hello == "ZDRAVSTVUJTE")
			cout << "Case " << count << ": " << "RUSSIAN" << "\n";
		else if (hello == "#")
			break;
		else
			cout << "Case " << count << ": " << "UNKNOWN" << "\n";
		count++;
	}

	return 0;
}
