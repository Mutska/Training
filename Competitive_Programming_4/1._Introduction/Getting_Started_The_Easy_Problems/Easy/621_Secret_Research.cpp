//2019-12-31 Secret Research by Mutska

#include <iostream>
#include <string>
using namespace std;

int main(){

	string s;
	int T;
	cin >> T;
	while(T--){
		cin >> s;
		if (s == "1" || s == "4" || s == "78" )
			cout << "+" << "\n";
		else if (s.size() > 1 && s[s.length() -1] == '5' && s[s.length() - 2] ==  '3')
			cout << "-" << "\n";
		else if (s.size() > 1 && s[0] == '9' && s[s.length() - 1 ] == '4')
			cout << "*" << "\n";
		else if (s.size() > 2 && s[0] == '1' &&  s[1] == '9' && s[2] == '0')
			cout << "?" << "\n";
		//else if (s.size() > 0 && (s[0] == '9' || s[s.length() -1] == '4'))
		//	cout << "*" << "\n";
		else if ((s.size() > 0 && s[0] == '1') || (s.size() > 1 && s[1] == '9') || (s.size() > 2 && s[2] == '0'))
			cout << "?" << "\n";
		else
			cout << "?" << "\n";
	
	}

	return 0;
}
