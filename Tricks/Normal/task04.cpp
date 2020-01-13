/* Given n random integers, print the distinct (unique) integers in sorted order.
 * */
#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

int main() {
	vector<int> v = {1, 2, 2, 2, 3, 3, 2, 2, 1};
	sort(ALL(v)); UNIQUE(v);
	for (auto &x: v) printf("%d\n", x);
}
