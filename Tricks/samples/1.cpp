#include <bits/stdc++.h>
#include <algorithm> 
//Maxium subarray sum

#define watch(x) cout << (#x) << " is " << (x) <<endl //Used for debugging
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i, a, b) for (int i = a; i<= b; i++)

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector <iii> viii;

int oo = 0x3f3f3f3f; //Infinity for integers, big enough, 2*oo will not overflow
double inf = 1.0/0.0; //to represent double infinity

//Tips

//1.- use this  flags for: g++ -std=c++11 -O2

//2.- result = something ? b : c; (if something is true then b else c)

//3.- Instead  of "&&" use "and" , Instead "||" use "or"

//4.- Instead of push_back() in STL emplace_back() can be used because it is much faster and instead of allocating memory somewhere else and then appending it directly allocates memory in the container.

//5.- multipy result with 2 -> result = result << 1

//6.- divide result by 2 -> result = result >> 1

//7.- swap a and b fast method and doesn't require a third variable
	//a  ^= b
	//b  ^= a
	//a  ^= b
	
//8.- The C++ standard objects for input and output, cin and cout, aren’t slow by default. What makes them so slow is the synchronization with C buffers. If you use ios::sync_with_stdio(false) at the beginning of your code, you’ll make cin and cout as fast as printf and scanf, but you’ll no longer be able to use neither printf nor scanf

//9.- void using strlen()
//
//  Use of strlen() can be avoided by:
//for (i=0; s[i]; i++)
//{
//}
// loop breaks when the character array ends.

//10.- Using Inline functions: We can create inline functions and use them without having to code them up during the contest. Examples: (a) function for sieve, (b) function for palindrome.

//11.-Maximum size of the array: We must be knowing that the maximum size of array declared inside the main function is of the order of 10^6 but if you declare array globally then you can declare its size upto 10^7.









int main(){

	cout << "gcd(6, 20) = " << __gcd(6, 20) << endl;

int best = 0, sum = 0;

int arreglo[8] = {-1, 2, 4, -3, 5, 2, -5, 2};

watch(inf);

for (int k = 0; k < 8; k++){

	sum = max(arreglo[k], sum + arreglo[k]);
	cout<<"SUM is: "<<sum<<"\n";
	best = max(best, sum);
	cout<<"BEST is: "<<best<<"\n";

}

cout<<best<<"\n";
return 0;

}
