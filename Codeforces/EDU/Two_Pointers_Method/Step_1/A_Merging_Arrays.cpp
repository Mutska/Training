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

	int i = 0, j = 0, k = 0;

	vector<int>c(n + m);

	while(i < n || j < m) {
		if (j == m || (i < n && a[i]  < b[j])) c[k++] = a[i++];
		else c[k++] = b[j++];
	}

	for(int x: c) cout << x << " ";
	cout << "\n";





	return 0;
}
