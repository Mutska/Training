#include <bits/stdc++.h>
using namespace std;

int numWays_Recursive(int m, int n) {
	if(m == 1 || n == 1) return 1;
	return numWays_Recursive(m-1, n) + numWays_Recursive(m, n -1);
}
int ways[2][2] = {0};
int M = 2, N = 2;
int was(int m, int n) {
	if(m == 0 && n == 0) 
		ways[0][0] = ways[0][1] + ways[1][0];
	if(m == M) {
		ways[m][n] = 1;
		return was(m-1, n);
	}
	if(n == N) { 
		ways[m][n] = 1;
		return was(m, n-1); 
	}
	else ways[m][n] = was(m-1, n) + was(m, n - 1);
	return ways[m][n];
}

// Assuming the dimensions m and n are non-negative integers
int numWays_Bottom_Up(int m, int n){
	int ways3[m][n];
	// Number of ways to reach bottom right corner from last column of grid is 1
	for(int i = 0; i <= m-1 ; i++){
		ways3[i][n-1] = 1;
	}
	// Number of ways to reach bottom right from corner last row of grid is 1 too
	for(int j = 0; j <= n-1 ; j++){
		ways3[m-1][j] = 1;
	}
	for(int i = m-2; i >= 0; i--){
		for(int j = n-2; j>=0; j--){
			ways3[i][j] = ways3[i][j+1] + ways3[i+1][j];
		}
	}
	return ways3[0][0];
}

int main(){

	printf("Number of unique ways to reach your home from a 4X3 grid is: %d. \n", numWays_Bottom_Up(4,3) );
	printf("Number of unique ways to reach your home from a 3X3 grid is: %d. \n", numWays_Bottom_Up(3,3) );
	printf("Number of unique ways to reach your home from a 7X10 grid is: %d. \n", numWays_Bottom_Up(7,10) );
	cout << numWays_Recursive(3,3) << "\n";
	cout << was(2,2) << "\n";

	return 0;
}
