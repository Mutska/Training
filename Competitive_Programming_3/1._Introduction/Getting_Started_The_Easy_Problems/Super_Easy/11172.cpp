//2019-12-30 Relational Operators by Mutska

#include <iostream>

using namespace std;


int main(){

	int number_tests;
    long long int a, b;

	cin >> number_tests;


	while(number_tests--){
	
	cin >> a >> b;

	if(a > b)
		cout << ">" << "\n";
	else if (a < b )
		cout << "<" << "\n";
	else
		cout << "=" << "\n";
	
	
	}

	
	return 0;

}
