//2020-01-01 Tarriff Plan by Mutska

#include <iostream>
#include <cmath> 

using namespace std;

int main(){

	int T, N, a, count = 1;
	int Mile, Juice;
	cin >> T;
	while(T--){
		Mile = 0;
		Juice = 0;
		cin >> N;
		while(N--){
			cin >> a;
			Mile  += (( a /30) + 1) * 10; 
			Juice += (( a /60) + 1) * 15;
		}
		if(Mile < Juice)
			cout << "Case " << count << ": "  << "Mile "<< Mile << "\n";
		if(Juice < Mile)
			cout << "Case " << count << ": "  << "Juice "<< Juice << "\n";
		if(Mile == Juice)
			cout << "Case " << count << ": "  << "Mile Juice "<< Mile << "\n";
		count++;
	
	}
	return 0;
}
