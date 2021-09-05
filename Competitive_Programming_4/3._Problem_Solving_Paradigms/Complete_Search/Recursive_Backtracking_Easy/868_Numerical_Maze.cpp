#include <iostream>
#include <cstring>

using namespace std;
int N, M, r, c, sum;
bool ok = false;
int maze[100][100];
// left, right, down, up				
int dir1[4] = {0 ,0, 1, -1,};
int dir2[4] = {-1,1, 0,  0,};
bool used[100][100]; 

void backtrack(int target, int it, int row, int col){
	if(row < 1  || col < 1  || row > N || col > M) return; 
	if (used[row][col]) return;
	if (row == N && maze[row][col] == it) {
			if (row + col < sum) r = row, c = col, sum = row + col;
			ok = true;
			return;
	}
	used[row][col] = 1;
	for (int i = 0; i < 4; ++i) {
		if (target == it){
			if(maze[row][col] == it)
				backtrack(target + 1, 1, row + dir1[i], col + dir2[i]);
		}else{
			if(maze[row][col] == it)
				backtrack(target, it + 1, row + dir1[i], col + dir2[i]);
		}
	}
	used[row][col] = 0;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, start;
	cin >> t;
	while(t--) {
		memset(used, 0, sizeof used);
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			for(int j = 1; j <= M; ++j){
				cin >> maze[i][j];
			}
		sum = 1000;
		ok = false;
		for (int j = 1; j <= M; ++j) {
			if (maze[1][j] == 1) {
				backtrack(1, 1, 1, j);
			}
			if (ok) {
				start = j;
				break;
			}
		}
		cout << 1 << " " << start << "\n";
		cout << r << " " << c << "\n";
		if(t) cout << "\n";
	}
	return 0;
}
