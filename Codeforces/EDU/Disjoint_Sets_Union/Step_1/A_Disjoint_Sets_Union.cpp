#include <iostream>
#include <vector>


using namespace std;

typedef vector<int> vi;

class UnionFind {
	
	private:
		vi p, rank, setSize;
		int numSets;

	public:
		UnionFind(int N) {
			p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
			rank.assign(N, 0);
			setSize.assign(N, 1);
			numSets = N;

		}
			int findSet(int i) {
				return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
			}
			
			bool isSameSet(int i, int j) {
				return findSet(i) == findSet(j);
			}

			int numDisjointSets() {
				return numSets;
			}

			int sizeOfSet(int i) {
				return setSize[findSet(i)];
			}

			void unionSet(int i, int j) {
				if (isSameSet(i, j)) return;
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) swap(x, y);
				p[x] = y;
				if (rank[x] == rank[y]) ++rank[y];
				setSize[y] += setSize[x];
				--numSets;
			}

};


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;

	cin >> n >> m;

	UnionFind UF(n);

	string query;
	int u, v;

	while(m--) {
		cin >> query >> u >> v;
		--u, --v;
		if (query == "union") UF.unionSet(u,v);
		else if (UF.isSameSet(u,v)) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;

}
