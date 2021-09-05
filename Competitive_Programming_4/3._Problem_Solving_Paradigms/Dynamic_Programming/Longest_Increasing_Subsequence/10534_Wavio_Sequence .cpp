// O(n log k)
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n;
vi A;


int LIS(int k, int x, vector<int> &L) {
  if(k == 0) return 0;
  int l = -1; // a[l] < x
  int r = k;
  // a[r] >= x;
  while(r > l + 1) {
    int m = (l+r) / 2;
    if(L[m] < x) l = m;
    else r = m;
  }
  return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n) {
        A.assign(n, 0);
        for(int i = 0; i < n; ++i) cin >> A[i];
        int k = 0;
        vi L(n), lis(n);
    
        for (int i = 0; i < n; ++i) {
            int pos = LIS(k, A[i], L);
            L[pos] = A[i];
            if (pos == k) k = pos+1;
            lis[i] = pos + 1;
        }

        reverse(A.begin(), A.end());

        int m = 0;
        vi L2(n), lds(n);

        for (int i = 0; i < n; ++i) {
            int pos2 = LIS(m, A[i], L2);
            L2[pos2] = A[i];
            if (pos2 == m) m = pos2+1;
            lds[i] = pos2 + 1;
        }
        reverse(lds.begin(), lds.end());
        int maximum = 0;
        for(int i = 0; i < n; ++i) maximum = max(maximum, min(lis[i], lds[i]));
        cout << 2*maximum - 1 << "\n";
  }
  
  return 0;
}