//2020-01-01 Zapping by Mutska
#include <iostream> 
#include <cmath>

using namespace std;

int main(){
	int a, b, m1, m2, m3;

	while(cin >> a >> b){
		if(a == -1 && b == -1)
			break;
		m1 = 100;
		m2 = 100;
		m3 = 100;
		if( a == b)
			m1 = 0;
		if( a > b){
			m2 = a - b;
			m3 = (b + 100) - a;	
		}
		if(b > a){
			m2 = b - a;
			m3 = (a + 100) - b;
		}
		cout << min(m1,min(m2,m3)) << "\n";


	
	}

	return 0;
}
