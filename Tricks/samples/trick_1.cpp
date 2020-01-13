#include <iostream>
#include <numeric>


using namespace std;

// The Iota Algorithm  creates a range of sequentially increasing values.
// by assigning an initial value to *first, then incrementing that
// value using prefix ++. 
int main(){

	int  a[10] = {0}; //Initialized with all the values equal to zero
	char b[10] = {0}; //Initialized with all the values equal to the NULL character
	
	cout <<"Before using iota: " <<endl;

	for(auto x: a)
		cout<<x<<endl;

	for(auto x: b)
		cout<<x<<endl;

	iota(a, a+10, 10);  //Assigns the consecutive values starting at 10
	iota(b, b+10,'a');  //Assigns the consecutive values starting at 'a'
	
	cout <<"After using iota: " <<endl;
	for(auto x: a)
		cout<<x<<endl;

	for(auto x: b)
		cout<<x<<endl;

	return 0;
}

