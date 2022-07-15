#include <iostream>
#include <vector>

using namespace std;


int main() {

	int n, m;

	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];

	vector<int> b(m);
	for(int i = 0; i < m; ++i) cin >> b[i];

	int i = 0;
	long long res = 0, count = 0;

	for(int j = 0; j < m; ++j) {
		if (j > 0 && b[j] == b[j-1]) res += count;
		else {
			count = 0;
			int current = i;
			while(i < n && a[i] != b[j] && a[i] < b[j]) ++i;
			while(i < n && a[i] == b[j]) ++i, ++count;
			res += count;
		}
	}

	cout << res << "\n";




	return 0;
}
