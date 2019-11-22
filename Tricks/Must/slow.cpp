#include <iostream>

using namespace std;

int main(){

	long long x=10;
	int k;
	cin>>k;
	for (int i = 1; i < k;i++){
		x *= 9;
		x = x % 1000000007;
	}

	cout<<x<<"\n";








}
