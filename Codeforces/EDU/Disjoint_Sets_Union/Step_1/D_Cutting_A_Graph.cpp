#include <iostream>
#include <algorithm>
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

struct query{
	string type;
	int u, v;
};


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, u, v;
	cin >> n >> m >> k;

	UnionFind UF(n);

	vector<query> order;
	vector<string> answer;

	for (int i = 0; i < m; ++i) cin >> u >> v;

	for (int i = 0; i < k; ++i) {
		query q;
		cin >> q.type >> q.u >> q.v;
		q.u--; q.v--;
		order.push_back(q);
	}

	for(int i = k - 1; i >= 0; --i) {

		u = order[i].u;
		v = order[i].v;
	
		if (order[i].type == "ask") {
			if (UF.isSameSet(u,v)) answer.push_back("YES");
			else answer.push_back("NO");
		} else {
			UF.unionSet(u, v);
		}

	}

	reverse(answer.begin(), answer.end());


	for(string &s: answer) cout << s << "\n";

	return 0;

}
