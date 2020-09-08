#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>

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
    string input;
    int T, count, acorns;
    cin >> T;
    while(T--) {
        vector<string> pairs;
        unordered_set<int> cycles;
        unordered_map<string, int> mapping;
        count = acorns =  0;
        while(cin >> input) {
            if(input[0] == '*') break;
            pairs.emplace_back(input);
        }
        cin >> input;
        for(int i = 0; i < input.size(); i++) {
            if(input[i] != ',') { 
                string s(1, input[i]);
                mapping[s] = count, count++;
            }
        }
        UnionFind forest(count);
        for(auto p: pairs) {
            string first(1,  p[1]);
            string second(1, p[3]);
            if(forest.isSameSet(mapping[first], mapping[second])) cycles.insert(mapping[first]);
            forest.unionSet(mapping[first], mapping[second]);
        }
        for(int i = 0; i < count; i++) 
            if(forest.sizeOfSet(i) == 1) acorns++;    
        cout << "There are " << (forest.numDisjointSets() - acorns - cycles.size())
             << " tree(s) and " << acorns << " acorn(s).\n";
    }
    return 0;
}