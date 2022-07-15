#include <bits/stdc++.h>
using namespace std;
vector <int> v;
vector<int> answers;
int minimum, n;

void backtrack(int swaps) {

  if (is_sorted(v.begin(), v.end())) {
    minimum = min(minimum, swaps);
    if (swaps != 0) answers.emplace_back(swaps);
    return;
  }
  for(int i = 0; i < n; ++i) {
      if(i + 1 < n && v[i] > v[i+1]) {
        swap(v[i], v[i+1]);
        backtrack(swaps + 1);
        swap(v[i], v[i+1]);
    }
  }

}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  int c=1;
  while(cin >> n, n){
    v.assign(n, 0);
    answers.clear();
    minimum = 200;
    for(int i=0; i<n; ++i) cin >> v[i];
  backtrack(0);
  int total = 0;
  for(int &a: answers)
    if(a == minimum) ++total;
  cout << "There are " << total <<" swap maps for input data set " << c++ << ".\n";
  }
  return 0;
}