#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>

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
    int C, R, count;
    string A, B;
    while(cin >> C >> R ,(C || R)) {
        unordered_map<string, int> animals;
        set<int> largest;
        largest.insert(-1);
        UnionFind Chains(C);
        count = 0;
        while(C--) {
            cin >> A;
            animals[A] = count;
            count++;
        }
        while(R--) {
            cin >> A >> B;
            Chains.unionSet(animals[A], animals[B]);
            largest.insert(-(Chains.sizeOfSet(animals[A])));
        }
        cout << - *(largest.begin()) << "\n";
    }


    return 0;
}