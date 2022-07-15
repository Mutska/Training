#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


struct elephant{
  int index;
  int size;
  int IQ;
};

bool order(elephant &a, elephant &b) {
  return a.IQ > b.IQ;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<elephant> a;
  int s, iq, idx = 0;

  while(cin >> s >> iq) {
    elephant e;
    e.size = s;
    e.IQ = iq;
    e.index = ++idx;
    a.push_back(e);
  }
  sort(a.begin(), a.end(), order);
  //for(auto &b: a) cout << b.index << " " << b.size << " " << b.IQ << "\n";

  int n = a.size();
  vector<int> d(n, 1), p(n, -1);

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < i; ++j) {
      if (a[j].size < a[i].size && a[j].IQ > a[i].IQ && d[i] < d[j] + 1) d[i] = d[j] + 1, p[i] = j;
    }
  
  int ans = d[0], pos = 0;

  for(int i = 1 ; i < n; ++i)
    if (d[i] > ans) ans = d[i], pos = i;

  vector<elephant> subseq;

  while(pos != -1) subseq.push_back(a[pos]), pos = p[pos];

  reverse(subseq.begin(), subseq.end());

  cout << subseq.size() << "\n";
  for(auto &b: subseq) cout << b.index << "\n";//<< " " << b.size << " " << b.IQ << "\n";
  //cout << "\n";
  return 0;
}