#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int n, k;
vector<int> a;

bool good(double x) {
	int s = 0;
	for(int i = 0; i < n; ++i) {
		s += floor(a[i] / x);
	}
	return s >= k;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	double l = 0; // l is good
	double r = 1e8; // r is bad

	for(int i = 0; i < 50; 	++i) {
		double m = (l + r) / 2;
		if (good(m)) l = m;
		else r = m;
	}

	cout << setprecision(10) << l << "\n";

	return 0;
}
