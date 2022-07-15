#include <iostream>
#include <vector>


using namespace std;


int n, k;
vector<long long> a;


bool good(long long sum) {

	long long current = a[0];
	if (current > sum) return false;
	long long segments = 0;

	for(int i = 1; i < n; ++i) {
		if (a[i] > sum) return false;
		if (current + a[i] > sum) {
			current = 0; 
			++segments;
		}
		current += a[i];
	}
	++segments;

	return segments <= k;
}

int main() {
	
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; ++i) cin >> a[i];


	long long l = 0; // bad
	long long r = 10e14; // good;

	 while(r > l + 1) {
	 	long long sum = (l + r) / 2;
	 	if (good(sum)) r = sum;
	 	else l = sum;
	 }

	cout << r << "\n";

	return 0;
}
