#include<iostream>
#include<vector>



using namespace std;


vector<vector<bool>> whites;
vector<string> board;
int N;

int dr [] = {1, 1, 0, -1,-1, 0};
int dc [] = {0, 1, 1, 0, -1, -1};

bool white;

void dfs(int r, int c, char player) {

	whites[r][c] = true;
	if (white) return;
	if (player == 'w'  && c == N - 1) {
		white = true;
		return;
	}

	for(int d = 0; d < 6; ++d) {

		if (r + dr[d] < 0 || r + dr[d] >= N) continue;
		if (c + dc[d] < 0 || c + dc[d] >= N) continue;

		if (board[r + dr[d]][c + dc[d]] == player && !whites[r + dr[d]][c + dc[d]]) {
			dfs(r + dr[d], c + dc[d], player);
		}
	}
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Case = 0;

	while(cin >> N, (N || 0)) {
		board.clear();
		whites.clear();
		whites.resize(N, vector<bool>(N));
		white = false;
		string s;
		for(int i = 0; i < N; ++i) {
			cin >> s;
			board.push_back(s);
		}

		for(int i = 0; i < N;++i){
			if (board[i][0] == 'w') dfs(i, 0, 'w');
		}

		if (white) cout << ++Case << " W\n";
		else cout << ++Case << " B\n";
	}

	return 0;
}
