#include <bits/stdc++.h>

using namespace std;

int main(){
//Calculating the number of digits directly: To calculate number of digits in a number, instead of looping you can efficiently use log :
//Number of digits in N =floor(log10(N)) + 1;  
//BY check!!!
int N;
cin >> N;
N = floor(log10(N)) + 1;
cout << N << endl;

	return 0;
}
