#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


string s;
int r, n;
bool taken[31];

void backtrack(string c, int idx) {
	if (c.size() == r ) {
			cout << c << "\n";
			return;
	}
	for (int i = idx; i < n; ++i) {
		//if (c.back() <= s[i]) 
		if(!taken[i]) {
			taken[i] = 1;
			backtrack(c + s[i], i + 1);
			taken[i] = 0;
		}
		while (s[i] == s[i + 1])++i;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> s >>  r) {
		n = s.size();
		sort(s.begin(), s.end());
		s += '1';
		backtrack("",0);
	}
	return 0;
}
