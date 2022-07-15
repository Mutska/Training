#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;
vi A, p;

void print_LIS(int i){
  if (p[i] == -1) { printf("%d\n", A[i]); return; }
  print_LIS(p[i]);
  printf("%d\n", A[i]);
}

int upper_bound(vi &L, int k, int x) {
  if(k == 0) return 0;
  int l = -1; // a[l] < x
  int r = k; // a[r] >= x;
  while(r > l + 1) {
      int m = (l+r) / 2;
      if(L[m] < x) l = m;
      else r = m;
  }
  return l;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a;
  while(cin >> a) A.emplace_back(a);
  n = A.size();
  int k = 0, lis_end = 0;
  vi L(n, 0), L_id(n, 0);
  p.assign(n, -1);

  for (int i = 0; i < n; ++i){
    //int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
    int pos = upper_bound(L, k, A[i]);
    L[pos] = A[i];
    L_id[pos] = i;
    p[i] = pos ? L_id[pos-1] : -1;
    if (pos == k) {
      k = pos+1;
      lis_end = i;
    }
  }
  cout << k << "\n-\n";
  print_LIS(lis_end);
  return 0;
}