#include <iostream>
#include <climits>
#include <vector>


using namespace std;

typedef vector<int> vi;

class UnionFind {
	
	private:
		vi p, rank, setSize, points;
		int numSets;

	public:
		UnionFind(int N) {
			p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
			points.assign(N, 0);
			rank.assign(N, 0);
			setSize.assign(N, 1);
			numSets = N;

		}
			int findSet(int i) {
				return (p[i] == i) ? i : (findSet(p[i])); 
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

			int get(int x) {

				if (p[x] == x) return points[x];

				return points[x] + get(p[x]);
				
			}

			void add(int x, int v) {
				int y = findSet(x);
				points[y] += v;
			}


			void unionSet(int i, int j) {
				if (isSameSet(i, j)) return;
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) swap(x, y);
				p[x] = y;
				points[x] -= points[y];
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
		cin >> query;
		cin >> u;
		--u;
		if (query == "join") {
			cin >> v;
			--v;
			UF.unionSet(u, v);
		} else if (query == "add") {
			cin >> v;
			UF.add(u, v);
		} else {
			cout << UF.get(u) << "\n";
		}
	}

	return 0;
}
