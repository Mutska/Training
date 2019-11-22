#include <iostream>

using namespace std;

int main(){
	//Check if a number is even or odd.(Fast for large numbers)
	int num;
    cin >> num;	
	if(num & 1)
		cout << "it's odd";
	else
		cout << "it's even";
	
	return 0;
}
