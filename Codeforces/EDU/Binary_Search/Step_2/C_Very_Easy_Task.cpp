#include <iostream>


using namespace std;

long long n, x, y;

bool good(long long time) {
	return ((time / x) + (time / y)) >= (n - 1);
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> y;
	
	long long initial = min(x, y);

	if (n == 1) cout << initial << "\n";
	else {

		long long l = 0; // bad 
		long long r = 1; // good

		while(!good(r)) r *= 2; 

		while(r > l + 1) {
			long long time  = (l + r) / 2;
			if (good(time)) r = time;
			else l = time;
		}

		r += initial;

		cout << r << "\n";
	}

	return 0;
}
