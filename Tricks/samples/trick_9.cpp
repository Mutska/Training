#include <bits/stdc++.h>

using namespace std;

int main(){
// Calculating the most significant digit: To calculate the most significant digit of any number log can be directly used to calculate it.
//By check !!!!
//Suppose the number is N then 
int N;
int X;
cin >> N;
double K = log10(N);
K = K - floor(K);
X = pow(10, K);
cout << X << endl; //X will be the most significant digit.
//now K = K - floor(K);
//int X = pow(10, K);
//X will be the most significant digit.

	return 0;
}
