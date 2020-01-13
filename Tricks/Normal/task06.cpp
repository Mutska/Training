/* Given a list of sorted integers L of size up to 1M items, 
 * determine wheter a value v exists in L with no more that 20 
 * comparisons.
 **/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 5, L[] = {10, 7, 5, 20, 8}, v = 7;

	sort(L, L + n);
	printf("%d\n", binary_search(L, L + n, v));
}
