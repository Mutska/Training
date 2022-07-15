#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;


vector<string> grid;
int size, n, m;
bool used[51][51] = {false};
// S, SE, E, NE, N, NW, W, SW
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};


bool backtrack(int r, int c, string &s, int i, int x, int y) {
	if (r < 0 || r >= n) return false;
	if (c < 0 || c >= m) return false;
	if (grid[r][c] != s[i]) return false;
	if (i == size - 1) return true;
	used[r][c] = true;
	bool found = false;
	if (i >= 1) {
		found |= backtrack(r + x, c + y, s, i + 1, x, y);
	} else{

		for(int d = 0; d < 8; ++d) {
			if(!(used[r+dr[d]][c + dc[d]])) found |= backtrack(r + dr[d], c + dc[d], s, i + 1, dr[d], dc[d]);
			if(found) break;
		}
	}
	used[r][c] = false;
	return found;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,  k;
	string s;
	cin >> t;
	while(t--) {
		grid.clear();
		vector<string> words;
		cin >> n >> m;
		for(int i = 0; i < n; ++i) {
			cin >> s;
    		std::for_each(s.begin(), s.end(), [](char & c) { c = ::tolower(c);});
			grid.push_back(s);
		}
		cin >> k;
		while(k--) {
			cin >> s;
    		std::for_each(s.begin(), s.end(), [](char & c) { c = ::tolower(c);});
			words.push_back(s);
		}
		for(string &s: words) {
			size = s.size();
			bool found = false;
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					found = backtrack(i,j, s, 0, 0, 0);
					if(found) {
						cout << i + 1 << " " << j + 1  << "\n";
						break;
					}
				}
				if(found) break;
			}
		}
		if(t) cout << "\n";	
	}
	return 0;
}
