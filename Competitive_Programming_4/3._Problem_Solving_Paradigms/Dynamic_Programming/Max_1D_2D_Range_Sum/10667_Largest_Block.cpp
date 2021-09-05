#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p, s, n, r1, c1, r2, c2;
	cin >> p;
	while(p--){
		cin >> s;		
		vector<vector<int>> A(s, vector<int>(s,1));
        cin >> n;
        while(n--) {
            cin >> r1 >> c1 >> r2 >>c2;
            --r1, --c1, --r2, --c2;
            for(int i = r1; i <= r2; ++i)
                for(int j = c1; j <= c2; ++j) A[i][j] = 0;
        }
		//for(int i = 0; i < s; ++i) {
		//	for(int j = 0; j < s; ++j) cout << A[i][j] << " ";
		//	cout << "\n";
		//}

		for(int i = 0; i < s; ++i){
			for(int j = 0; j < s; ++j) {
				if (j > 0) A[i][j] += A[i][j-1];
			}
		}

		int maxSubRect = -1;
		for(int l = 0; l < s; ++l)
			for(int r = l; r < s; ++r) {
				int subRect = 0;
				for(int row = 0; row < s; ++row) {
					int toadd  = 0;
					if (l > 0) {
						toadd = A[row][r] - A[row][l-1];
						if (toadd == (r - l + 1)) subRect += toadd;
						else subRect = 0;
					} else {
						toadd = A[row][r];
						if (toadd == (r - l + 1)) subRect += toadd;
						else subRect = 0;
					}
					//cout << "subrect from l = " << l << ", r = " << r << " in row = " << row << 
					//" with toadd equal to " << toadd << "\n";
					// Kadane's algorithms on rows
				 	if (subRect < 0) subRect = 0;
					maxSubRect = max(maxSubRect, subRect);
				}
				//if (subRect == 18) {
				//	cout << " 18  from: \n";
				//	cout << "subrect from l = " << l << ", r = " << r  << "\n";
				//}
			}
		cout << maxSubRect << "\n";
	}
	return 0;
}
