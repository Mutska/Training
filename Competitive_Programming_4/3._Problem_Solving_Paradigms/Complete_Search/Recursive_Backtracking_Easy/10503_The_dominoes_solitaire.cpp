#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, l1, l2, r1, r2;
vector<pair<int, int>> dominoes;
bool taken[15];
bool ok = false;


void backtrack(int step, int current) {
	if (ok) return;
	if (step == n) {
		if (current == r1) ok = true;
		return;
	}
	for (int i = 0; i < m; ++i) {
		if (!taken[i]) {
			if (dominoes[i].first == current) {
				taken[i] = 1;
				backtrack(step+1, dominoes[i].second);
				taken[i] = 0;
			}
			if (dominoes[i].second == current) {
				taken[i] = 1;
				backtrack(step+1, dominoes[i].first);
				taken[i] = 0;
			}
		}
	}
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  while(cin >> n, n != 0) {
	memset(taken, 0, sizeof taken);
	dominoes.clear();
	ok = false;
	cin >> m;
	cin >> l1 >> l2;
	cin >> r1 >> r2;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		dominoes.push_back({a, b});
	}
	backtrack(0, l2);
	if (ok) cout << "YES\n";
	else cout << "NO\n";
  }
  return 0;
}
