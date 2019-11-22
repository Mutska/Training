#include <iostream>

using namespace std;

int main(){
	//Round to nearest integer:
	double a;
	cin >> a;
	int result = (int)((double)a + 0.5);
	cout << result << endl;

	return 0;
}
