//2020-01-20 Free Spots by Mutska

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	
	ios::sync_with_stdio(0);
	vector<int>  cordX, cordY;
	int spots[500][500];
   	int W, H, N, X1, X2, Y1, Y2, counter;
	while(cin >> W >> H >> N, (W || H || N)){
		counter = 0;
		for(int i = 0; i < W; i++)
			for(int j = 0; j < H; j++)
				spots[i][j] = 0;

		while(N--) {
			cin >> X1 >> Y1 >> X2 >> Y2;
			cordX.push_back(X1);
			cordX.push_back(X2);
			cordY.push_back(Y1);
			cordY.push_back(Y2);
			sort(cordX.begin(), cordX.end());
			sort(cordY.begin(), cordY.end());
			for(int i = cordX[0] - 1; i < cordX[1] ; i++ ) {
				for(int j = cordY[0] - 1; j < cordY[1]; j++) {
					if(spots[i][j] == 0) {
						spots[i][j] = 1;
						counter++;
					}		
				}
			}
			cordX.clear();	
			cordY.clear();	
		}
		if ((W*H - counter) == 0)	
			cout << "There is no empty spots.\n";
		else if ((W*H - counter) == 1)	
			cout << "There is one empty spot.\n";
		else
			cout << "There are "<< W*H - counter << " empty spots.\n";
	}








	return 0;
}
