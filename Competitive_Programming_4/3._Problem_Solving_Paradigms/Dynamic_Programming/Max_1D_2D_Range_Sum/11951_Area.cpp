#include <iostream>
using namespace std;

int A[110][110];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m, z;
  cin >> t;
  
  for(int K=1; K<=t; ++K){
    
    cin >> n >> m >> z;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        cin >> A[i][j];
        //A[i][j] *= -1;
        if (i > 0) A[i][j] += A[i-1][j];           // add from top
        if (j > 0) A[i][j] += A[i][j-1];           // add from left
        if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];// avoid double count
      }                                            // inclusion-exclusion
  int maxSubRect = 0; 
  int land = 0;                 // the lowest possible val
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)                  // start coordinate
      for (int k = i; k < n; ++k)
        for (int l = j; l < m; ++l) {            // end coord
          int subRect = A[k][l];                 // from (0, 0) to (k, l)
          if (i > 0) subRect -= A[i-1][l];       // O(1)
          if (j > 0) subRect -= A[k][j-1];       // O(1)
          if (i > 0 && j > 0) subRect += A[i-1][j-1]; // O(1)
          //if (subRect == 10) {
          //  cout << "(i,j) = (" << i << ", " << j << ")\n";
           // cout << "(k,l) = (" << k << ", " << l << ")\n";
          //}
          if(subRect <= z && land <= (k-i+1)*(l-j+1) ){
            if(land==(k-i+1)*(l-j+1)){
               maxSubRect = min(maxSubRect, subRect);
            }
            else{
                maxSubRect = subRect;
            }

            land = (k-i+1)*(l-j+1); 
            //cout << "(land,price) = (" << land << ", " << maxSubRect << ")\n";
          } // the answer is here
        }
    cout << "Case #" << K <<": ";
    cout << land <<" "<< maxSubRect << "\n"; 

  }
}