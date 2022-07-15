#include<iostream>
#include <iomanip>
#include<cmath>

using namespace std;


double C;

bool good(double x) {
	return (x*x + sqrt(x)) >= C;
}

int main() {


	cin >> C;

	double l = 0.0; // bad
	double r = sqrt(C); //g good

	for(int i = 0; i < 40; ++i) {
		double m = (l + r) / 2.0;
		if(good(m)) r = m;
		else l = m;
	}
	

	cout << setprecision(20) << r << "\n";


	return 0;
}
