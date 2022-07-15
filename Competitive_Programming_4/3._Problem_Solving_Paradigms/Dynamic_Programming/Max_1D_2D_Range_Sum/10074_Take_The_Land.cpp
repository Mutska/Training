#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m, (n || m)) {
	vector<vector<int>> A(n, vector<int>(m,0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> A[i][j];
			A[i][j] = 1 - A[i][j];
			//cout << A[i][j] << " ";
			if (j > 0) A[i][j] += A[i][j-1];
		}
		//cout << "\n";
	}

	//for(int i = 0; i < n; ++i) {
	//	for(int j = 0; j < m; ++j) cout << A[i][j] << " ";
	//	cout << "\n";
	//}

	int maxSubRect = -1;
	//cout << "n is: " << n << "\n";
	//cout << "m is: " << m << "\n";
	for(int l = 0; l < m; ++l)
		for(int r = l; r < m; ++r) {
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
		}
		cout << maxSubRect << "\n";
	}
	return 0;
}
