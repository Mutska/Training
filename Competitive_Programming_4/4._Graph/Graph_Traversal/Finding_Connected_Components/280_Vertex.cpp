#include<iostream>
#include<vector>
#include<sstream>



using namespace std;


enum {UNVISITED = 0, VISITED = 1};
vector<vector<int>> AL;
vector<int> dfs_num;

void dfs(int u) {
	for(int v: AL[u]) {
		if (dfs_num[v] == UNVISITED) {
			dfs_num[v] = VISITED;
			dfs(v); 
		}
	}
}



int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, u, v;

	while (cin >> V, (V || 0)) {

		AL.assign(V, vector<int>());
		cin.ignore();
		string s;

		while(getline(cin, s), s != "0"){

			stringstream ss(s);
			ss >> u;
			--u;
			while(ss >> v, v != 0) {
				--v;
				AL[u].push_back(v);
			}

		}
		int queries;
		cin >> queries;
		while(queries--) {
			cin >> v;
			--v;
			dfs_num.assign(V, UNVISITED);
			dfs(v);
			vector<int> unreachable;
			for(int i = 0; i < V; ++i)
				if ( dfs_num[i]==UNVISITED ) unreachable.push_back(i+1);
			cout << unreachable.size();
			for(int &i: unreachable) cout << " " << i;
			cout << "\n";

		}
	}
	return 0;
}
