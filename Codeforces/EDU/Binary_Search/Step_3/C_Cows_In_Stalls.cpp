#include <iostream>
#include <vector>


using namespace std;

long long n, k;
vector<long long> a;

bool good(long long distance) {

	long long total_cows = 1;
	long long last_cow = a[0];
	
	for(int i = 1; i < n; ++i) {
		if (a[i] - last_cow >= distance) {
			last_cow = a[i];
			++total_cows;
		}
	}

	return total_cows >= k;
}

int main() {


	cin >> n >> k;	
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];


	long long l = 0; // good
	long long r = 10e9; // bad


	while(r > l + 1) {
		long long distance = (l + r) / 2;
		if (good(distance)) l = distance;
		else r = distance;
	}

	cout << l << "\n";



	return 0;
}
