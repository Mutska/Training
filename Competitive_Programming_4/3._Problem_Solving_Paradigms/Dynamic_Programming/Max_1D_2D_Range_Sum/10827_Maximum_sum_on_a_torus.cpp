#include <iostream>
#include <vector>

using namespace std;

int A[160][160]; 


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		bool atleast = false;
		int maximum = INT32_MIN;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <n; ++j) {
				cin >> A[i][j];
        if(j<n-1) A[i][j+n] = A[i][j];
        if(i<n-1) A[i+n][j] = A[i][j]; 
        if(i<n-1 && j<n-1) A[i+n][j+n]=A[i][j]; 
				if(A[i][j] > 0) atleast = true;
				maximum = max(maximum, A[i][j]);
        //if (j > 0) A[i][j] += A[i][j-1];
			}
		}
		if(!atleast) {
			cout << maximum << "\n";
      continue;
		} 

  //cout << "\n\n\n";
  //for(int i = 0; i < (2*n)-1; ++i) {
	 //for(int j = 0; j < (2*n)-1; ++j) cout << A[i][j] << " ";
    //		cout << "\n";
	 // }


    for(int i = 0; i < 2*n - 1; ++i){
			for(int j = 0; j < 2*n -1; ++j) {
        if (i> 0)  A[i][j]+= A[i-1][j]; 
        if (j > 0) A[i][j] += A[i][j-1];
        if(i>0 && j>0) A[i][j] -= A[i-1][j-1]; 
      }
    }

 // 1 2 3 
//  4 5 6
 // 7 8 9
  
 //     1       2       3       1     2       1
 // (0,0), (0, 1), (0,2) , (1,1), (1, 2), (2, 2)
//  0
 // 1
//  2
int maxSubRect = -127*100*100; 
for(int i =0 ; i< 2*n-1 ; ++i){
  for(int j=0; j<2*n-1; ++j){
    for(int k=i; k<i+n && k<2*n-1; ++k){
      for(int l=j; l<j+n && l<2*n-1; ++l){
        int subRect = A[k][l]; 
        if(i>0) subRect -= A[i-1][l]; 
        if(j>0) subRect -= A[k][j-1]; 
        if(i>0 && j>0) subRect += A[i-1][j-1]; 
        maxSubRect= max(maxSubRect, subRect); 
      }
    }
  }
}

		cout << maxSubRect << "\n";  
}
return 0;

}
