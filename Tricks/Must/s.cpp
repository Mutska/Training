#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int k;

	cin >> k;
	
	cout << (10 * int ( pow(9, k-1))) % 1000000007 << endl;
	


	return 0;
}
