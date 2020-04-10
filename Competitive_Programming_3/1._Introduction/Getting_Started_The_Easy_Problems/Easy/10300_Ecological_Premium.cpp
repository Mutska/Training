//2019-12-31 Ecological Premium by Mutska

#include <iostream>

using namespace std;

int main(){
	
	int N, f, a, b, c;
	int total;
	cin >> N;
	while(N--){
		total = 0;
		cin >> f;
		while(f--){
			cin >> a >> b >> c;
			total += a*c;
		}
		cout << total << "\n";
	
	}

	return 0;
}
