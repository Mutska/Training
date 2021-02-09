#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int table[105][105]; // Needleman Wunsnch's algorithm

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    string a, b;
    int l;
    cin.ignore();
    while(T--){
      getline(cin, a);
      getline(cin, b);
      memset(table, 0, sizeof table);
      int n = a.size();
      int m = b.size();
      if(n == 0 && m == 0) {
        cout << "0\n";
        continue;
      } else if(n == 0 && m != 0) {
        cout << m << "\n";
        continue;
      } else if(n != 0 && m == 0) {
        cout << n << "\n";
        continue;
      }
      for(int i = 1; i <= n; ++i) table[i][0] = i * 1;
      for(int j = 1; j <= m; ++j) table[0][j] = j * 1;
      for(int i = 1; i <=n; ++i)
        for(int j = 1; j <=m; ++j){
          //match = 2 points, mismatch = -1 point
          table[i][j] = table[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1);
          //insert/delete = -1 point
          table[i][j] = min(table[i][j], table[i-1][j] + 1); //delete
          table[i][j] = min(table[i][j], table[i][j-1] + 1); //insert
        }
      cout << table[n][m] << "\n";
    }

  return 0;
}