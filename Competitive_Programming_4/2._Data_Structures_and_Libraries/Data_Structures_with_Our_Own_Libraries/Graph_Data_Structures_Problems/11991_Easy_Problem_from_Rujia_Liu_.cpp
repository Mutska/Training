#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vi> AL(1000001, vi());
    int N, M, n, index;
    while(cin >> N >> M) {
        index = 1;
        vector<int> cleaning;
        while(N--) {
            cin >> n;
            AL[n].emplace_back(index);
            cleaning.emplace_back(n);
            index++;
        }
        while(M--) {
            cin >> index >> n;
            if(index >  AL[n].size()) 
                cout << 0 << "\n";
            else
                cout << (AL[n])[index-1] << "\n";
        }
        for(auto element: cleaning)
            if(AL[element].size() != 0)
                AL[element].clear();
    }
    return 0;
}