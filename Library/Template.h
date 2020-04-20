#include <bits/stdc++.h>

//Macros
#define watch(x) cout << (#x) << " is " << (x) <<endl //Used for debugging
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i, a, b) for (int i = a; i<= b; i++)
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

using namespace std;

//Sinonimos
typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector <iii> viii;
typedef vector<ll> vll;

int oo = 0x3f3f3f3f; //Infinity for integers, big enough, 2*oo will not overflow
double inf = 1.0/0.0; //to represent double infinity


/*
int main() {
    // Given n random integers, print the distinct (unique) integers in sorted order.
	vector<int> v = {1, 2, 2, 2, 3, 3, 2, 2, 1};
	sort(ALL(v)); UNIQUE(v);
	for (auto &x: v) printf("%d\n", x);
}
*/