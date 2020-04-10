#include <iostream>
#include <unordered_map>
#include <vector>
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
    int T, F, count;
    string A, B;
    cin >> T;
    while(T--) {
        cin >> F;
        count = 0;
        UnionFind Friends(2*F); 
        unordered_map<string, int> net;
        while(F--) {
            cin >> A >> B;
            if(net.find(A) == net.end())  net[A] = count, count++;
            if(net.find(B) == net.end())  net[B] = count, count++;
            Friends.unionSet(net[A], net[B]);
            cout << Friends.sizeOfSet(net[A]) << "\n";
        }

    }

    return 0;
}