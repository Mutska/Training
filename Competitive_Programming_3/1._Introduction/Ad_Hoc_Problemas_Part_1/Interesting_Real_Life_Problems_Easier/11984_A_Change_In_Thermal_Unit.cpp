//2020-01-08 A Change in Thermal Unit by Mutska

#include <iostream>
#include <iomanip> 

using namespace std;

int main(){

	int T;
	double C, F,change;

	cin >> T;

	int count = 1;
	while(T--){
		cin >> C >> F;
		
		change = (9*C)/5 + 32;
		F += change;
		C =((F - 32)* 5)/9;

		cout << "Case " << count << ": "<<fixed << setprecision(2) << C << "\n";
		count++;
	
	
	}



	return 0;
}
