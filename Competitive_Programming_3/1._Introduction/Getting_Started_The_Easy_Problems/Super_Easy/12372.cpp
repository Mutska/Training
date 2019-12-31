//2019-12-30 Packing for Holiday by mutska

#include <iostream>

using namespace std;

int main(){


	int T, L, W, H, count = 1;
	cin >> T;

	while(T--){
		cin >> L >> W >> H;

		if(L > 20 || W > 20 || H > 20)
			cout << "Case " << count << ": " << "bad" << "\n";
		else
			cout << "Case " << count << ": " << "good" << "\n";
	
		count++;
	}


	return 0;
}
