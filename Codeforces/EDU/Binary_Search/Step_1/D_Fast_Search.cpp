#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;



int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	int k;
	cin >> k;

	while(k--) {
		int x1, x2;

		cin >> x1 >> x2;

		// Find closest to the right
		
		int l1 = -1; // a[l1] < x1
		int r1 = n; // a[r1] >= x1 min(i) 

		while(r1 > l1 +1) {
			int m = (l1 + r1) / 2;
			if (a[m] < x1) l1 = m;
			else r1 = m;
		}

		// Find closest to the left
		
		int l2 = -1; // a[l2] <= x2 max(i)
		int r2 = n; // a[r2] > x2

		while(r2 > l2 +1) {
			int m = (l2 + r2) / 2;
			if (a[m] <= x2) l2 = m;
			else r2 = m;
		}

		cout << l2 - r1 + 1 << "\n";	

	}
}
