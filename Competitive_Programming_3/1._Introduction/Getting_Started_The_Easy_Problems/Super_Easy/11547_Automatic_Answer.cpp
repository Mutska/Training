//2019-12-30 Automatic Answer by Mutska
#include <iostream>
#include <cstdlib> 
using namespace std;

int main(){
	
	long int t, n, digit, temp;
	long double result;

	cin >> t;

	while(t--){
		cin >> n;
		result = n * 567;
		result = result / 9;
		result = result + 7492;
		result = result * 235;
		result = result / 47;
		result = result - 498;
		if( abs(result) < 10)
			cout << 0 << "\n";
		else {
			temp = (long int) abs(result);
			temp = temp / 10;
			digit = temp % 10;
			cout << digit << "\n";
		}
	}


	return 0;

}
