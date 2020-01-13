#include <bits/stdc++.h>

using namespace std;

// Efficient trick to know if a number is a power of 2 sing the normal technique of division the complexity comes out to be O(logN), but it can be solved using O(v) where v are the number of digits of number in binary form.

/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x) 
{ 
  /* First x in the below expression is  
    for the case when x is 0 */
  return x && (!(x&(x-1))); 
}

int main(){

	int N;
	cin >> N;

	if(isPowerOfTwo(N))
		cout<< "This number is power of two" << endl;
	else
		cout << "This number is not power of two" << endl;


	return 0;
}
