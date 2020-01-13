#include <iostream>

using namespace std;
//Recursive
long long  modular_exponentiation(int n  , int k, long long  mod){


	long long  x;

	if(k == 0)return 1;

	//If k is even
	if(k % 2 == 0){
		x = modular_exponentiation(n, k/2, mod);
		x = (x * x) % mod;	
	}
	else{
		x = n % mod;
		x = (x * modular_exponentiation(n, k-1, mod) % mod) % mod;
	
	}
	cout<<"res is: "<<(x % mod)<<"\n";
	return x ;
	
}




int main(){

	int n,k;
	long long int mod = 1000000007;
	cin>>n>>k;
	cout<<(10*modular_exponentiation(n, k - 1, mod)) % mod<<"\n"; 



	return 0;
}
