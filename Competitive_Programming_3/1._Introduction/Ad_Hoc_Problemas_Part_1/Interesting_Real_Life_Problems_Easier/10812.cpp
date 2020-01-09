//2020-01-08 Beat the Spread!

#include <iostream>


using namespace std;

int main(){

	long long int s, d, x, y; 
	int T;

	cin >> T;

	while(T--){
		cin >> s >> d;
		x = s + d;
		y = s - d;
		
		if(y < 0 || x%2 == 1 || y%2 == 1)
			cout << "impossible\n";
		else
			cout << x/2 << " " << y/2 << "\n";
	}




	return 0;
}
