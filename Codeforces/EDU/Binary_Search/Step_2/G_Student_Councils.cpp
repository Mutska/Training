#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<long  long> a;
int k, n;

bool good(long long target) {

	long long space = target*k;

	for(long long &num: a) space -= min(target, num);

	return space <= 0;

}


int main() {

	cin >> k;
	cin >> n;

	long long ai;
	for(int i = 0; i < n; ++i) {
		cin >> ai;
		a.emplace_back(ai);
	}

	long long l = 0; // good;
	long long r = 20*10e9; // bad;


	while(r > l + 1) {
		long long councils = (l + r) / 2LL;
		if(good(councils)) l = councils;
		else r = councils;
	}

	cout << l << "\n";
	return 0;
}
