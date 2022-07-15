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

	vector<int>res(m);

	for(int j = 0; j < m; ++j) {
		while(i < n && a[i] < b[j]) ++i;
		res[j] = i;
	}

	for(int x: res) cout << x << " ";
	cout << "\n";





	return 0;
}
