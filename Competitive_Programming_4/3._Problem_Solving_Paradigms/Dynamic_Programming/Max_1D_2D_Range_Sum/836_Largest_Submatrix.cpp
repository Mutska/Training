#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	while(t--){
				
		cin >> s;
		int n = s.size();
		vector<vector<int>> A(n, vector<int>(n,0));
		for(int j = 0; j < n; ++j) {
			A[0][j] = s[j] - '0';
			if (j > 0) A[0][j] += A[0][j-1];

		}
		for(int i = 1; i < n; ++i){
			cin >> s;
			for(int j = 0; j < n; ++j) {
				A[i][j] = s[j] - '0';
				if (j > 0) A[i][j] += A[i][j-1];
			}
		}
		//for(int i = 0; i < n; ++i) {
		//	for(int j = 0; j < n; ++j) cout << A[i][j] << " ";
		//	cout << "\n";
		//}

		int maxSubRect = -1;
		for(int l = 0; l < n; ++l)
			for(int r = l; r < n; ++r) {
				int subRect = 0;
				for(int row = 0; row < n; ++row) {
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
		if(t) cout << "\n";
	}
	return 0;
}
