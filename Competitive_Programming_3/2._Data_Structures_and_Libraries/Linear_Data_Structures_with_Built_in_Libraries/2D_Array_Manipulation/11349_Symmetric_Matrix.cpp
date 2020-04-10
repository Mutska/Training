//2020-01-20 Symmetric Matrix by Mutska

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	long long matrix[100][100], M;
	int T,n, count = 1;
	string a,b;
	bool flag;
	cin >> T;
	while(T--){
		cin >> a >> b >> n;
		flag = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> M;
				if(M < 0) flag = false;
				matrix[i][j] = M;	
			}
		}
		if(!flag){cout << "Test #" << count++ << ": Non-symmetric.\n"; continue;}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(matrix[i][j] != matrix[n - i - 1][n - j - 1]) {
					flag = false;
					break;
				}	
			}
		}
		if(!flag)
			cout << "Test #" << count++ << ": Non-symmetric.\n";
		else
			cout << "Test #" << count++ << ": Symmetric.\n";
	
	}



	return 0;
}
