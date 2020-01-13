//Generate all possible subsets of {0..N-1} for N = 20;
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))

int main(){
	int N = 20;
	for(int i = 0; i < (1 << N); ++i){
		int pos = i;
	while (pos){
		int ls = LSOne(pos);
		printf("%d ", __builtin_ctz(ls));

		pos -= ls;
	
	}
	printf("\n");
	}	
}
