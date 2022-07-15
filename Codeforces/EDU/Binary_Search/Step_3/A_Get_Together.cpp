#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>



using namespace std;


vector<long double> pos;
vector<long double> speed;
int n;

bool good(long double time) {

	long double l, r, minimum, maximum;

	minimum = INT64_MAX;
	maximum = INT64_MIN;
			
	for(int i = 0; i < n; ++i) {
		l = pos[i] - time*speed[i];
		maximum = max(l, maximum);
		r = pos[i] + time*speed[i];
		minimum = min(r, minimum);
	}
	return (minimum - maximum) > 0;
}

int main() {

	cin >> n;
	pos.assign(n,0);
	speed.assign(n,0);
	long double trivial = 0;

	for(int i = 0; i < n; ++i) cin >> pos[i] >> speed[i];

	if (n == 1) {
		cout << setprecision(20) << trivial << "\n";
	} else {

		long double l = 0; // bad
		long double r = 10e12L; // good

		for(int i = 0; i < 100; ++i) {
			long double time = (l + r) / 2.0;
			if (good(time)) r = time;
			else l = time;
		}

		cout << setprecision(20) << r << "\n";

	}

	return 0;
}
