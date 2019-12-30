//2019-12-30 Searching for Nessy by Mutska
#include <iostream>
#include <cmath>
using namespace std;


int main(){

	int tests_number, n, m;
	
	cin >> tests_number;


	while (tests_number--){
		cin >> n >> m;

		n -= 2;
		m -= 2;
		
		cout << fixed << (long int) (ceil(((double)n) / 3) * ceil(((double) m) / 3)) << "\n"; 	
	
	}





	return 0;
}
