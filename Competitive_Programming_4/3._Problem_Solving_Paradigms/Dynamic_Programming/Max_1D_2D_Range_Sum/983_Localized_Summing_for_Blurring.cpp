#include <iostream>
#include <vector>
using namespace std;

int A[1010][1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t = 0;
    while(cin >> n >> m){
        if (t++ > 0) cout << "\n";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
                if (i > 0) A[i][j] += A[i-1][j];           
                if (j > 0) A[i][j] += A[i][j-1];           
                if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
            }                                            
        vector<int> new_matrix;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j){                 
                int k = i + m - 1;
                int l = j + m - 1;
                if (k < n && l < n) {
                      int subRect = A[k][l];                
                      if (i > 0) subRect -= A[i-1][l];      
                      if (j > 0) subRect -= A[k][j-1];      
                      if (i > 0 && j > 0) subRect += A[i-1][j-1]; 
                      sum += subRect;
                      new_matrix.push_back(subRect);
                }
            }
        }
        int size = new_matrix.size();
        for(int &n: new_matrix) cout << n << "\n";
        cout << sum << "\n";
    }
    return 0;
}