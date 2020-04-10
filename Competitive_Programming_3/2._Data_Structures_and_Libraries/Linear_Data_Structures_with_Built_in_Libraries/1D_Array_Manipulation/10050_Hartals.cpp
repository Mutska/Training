//2020-01-14 Hartals by Mutska
#include <iostream>
#include <array>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	array<bool, 3651> simulation;
	int T, N, P, h,i, days;
	cin >> T;
	while(T--) {
		simulation  = { false };
		cin >> N >> P;
		days = 0;
		while(P--) {
			i = 1;
			cin >> h;
			while(1) {
				if(i*h > N) break; 
				if(i*h % 7 == 6 || i*h % 7 == 0 || simulation[i*h] == true) {i++; continue;}	
				simulation[i*h] = true;
				days++;
				i++;
			}

		}
		cout << days << "\n";
	
	}



	return 0;
}
