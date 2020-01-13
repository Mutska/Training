/* Read in a double echo it, but with a minimum field width of 7 
 * and 3 digits after the decimal point. 
 * */
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main(){
	double n;
	cin >> n;
	cout << setw(7) << setprecision(3) << fixed << n << endl;
	scanf("%lf", &n);
	printf("%*.*f\n",7,3,n);


}
