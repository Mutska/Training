#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public: 
    UnionFind(int N) {
        p.assign(N, 0); for(int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }
    int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets;}
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j) {
        if(isSameSet(i, j)) return;
        int x = findSet(i),  y = findSet(j);
        if(rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if(rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int T, N, i, j, num_queries, succ_queries, input;
    string query, line, in;
    cin >> T;
    while(T--) {
        cin >> N;
        num_queries = succ_queries = 0;
        UnionFind Network(N);
        cin.ignore();
        while(1) {
            getline(cin, line);
            if(line.size() == 0) break;
            stringstream ss(line);
            ss >> query >> i >> j;
            i--, j--;
            if(query == "c") 
                Network.unionSet(i, j);
            else if(Network.isSameSet(i,j))
                succ_queries++;
            else
                num_queries++;
        }
        cout << succ_queries << "," <<  num_queries << "\n";
        if(T) cout << "\n";
    }


    return 0;
}