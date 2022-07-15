#include <iostream>
#include <vector>


using namespace std;

typedef vector<int> vi;

class UnionFind {
	
	private:
		vi p;
		int numSets;

	public:
		UnionFind(int N) {
			p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;

		}
			int findSet(int i) {
				return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
			}
			
			bool isSameSet(int i, int j) {
				return findSet(i) == findSet(j);
			}

			void unionSet(int i, int j) {
				if (isSameSet(i, j)) return;
				int x = findSet(i), y = findSet(j);
				if (x > y) swap(x, y); // we have to change the heuristic a little bit to solve the problem
				p[x] = y;
			}

};


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;

	cin >> n >> m;

	UnionFind UF(n);

	string query;
	int u;
	bool leave = false;

	while(m--) {
		cin >> query >> u;
		--u;
		if (query == "-")  {
			if (u == n - 1) leave = true;
			else UF.unionSet(u, u + 1);
		} else {
			if (UF.findSet(u) == n - 1 && leave) cout << "-1\n";
			else cout << UF.findSet(u) + 1 << "\n";
		}
	}

	return 0;

}
