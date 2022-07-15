#include <iostream>


using namespace std;


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A[1001];

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int sum = 0;
		for(int i = 0; i < n; ++i)  {
			int l = 0;
			cin >> A[i];
			for(int j = 0; j < i; ++j) if (A[j] <= A[i]) ++l;
			sum += l;
		}
		cout << sum << "\n";
	}
	return 0;
}
