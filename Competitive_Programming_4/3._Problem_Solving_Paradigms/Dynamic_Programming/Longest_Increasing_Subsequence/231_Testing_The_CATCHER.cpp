#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
vi A, p;

void print_LIS(int i) {
  if (p[i] == -1) { cout << A[i] << "\n"; return; }
  print_LIS(p[i]);
  cout << A[i] << "\n";
}

int upper_bound(vi &L, int k, int x) {
  if(k == 0) return 0;
  int l = -1; // a[l] >= x
  int r = k; // a[r] < x;
  while(r > l + 1) {
      int m = (l+r) / 2;
      if(L[m] < x) r = m;
      else l = m;
  }
  return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a, c = 0;
    while(true) {

        A.clear();
        cin >> a;
        if (a == -1) break;
        else A.emplace_back(a);
        while(cin >> a) {
            if (a == -1) break;
            A.emplace_back(a);
        }
        n = A.size();
        //cout << "size is: " << n << "\n";
        int k = 0, lis_end = 0;
        vi L(n, 0), L_id(n, 0);
        p.assign(n, -1);
        if(c > 0) cout << "\n";
        for (int i = 0; i < n; ++i) {
            int pos = upper_bound(L, k,  A[i]);
            L[pos] = A[i];
            //for(auto l: L) cout << l << " ";
            //cout << "\n";
            L_id[pos] = i;
            p[i] = pos ? L_id[pos-1] : -1;
            if (pos == k) {
              k = pos+1;
              lis_end = i;
            }
        }
        cout << "Test #" << ++c << ":\n";
        cout << "  maximum possible interceptions: " << k << "\n";
        //print_LIS(lis_end);
        //if(t) cout << "\n";
  }
  return 0;
}
