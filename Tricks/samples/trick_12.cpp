#include <bits/stdc++.h>

using namespace std;

int main(){
//Copy Algorithm: used to copy elements from one container to another.
int source[5] = {0, 12, 34, 50, 80};
int target[5];
// copy 5 elements from source to target
copy_n(source, 5, target);

for(auto x: target)
	cout << x << " ";

cout << endl ;

	return 0;
}
