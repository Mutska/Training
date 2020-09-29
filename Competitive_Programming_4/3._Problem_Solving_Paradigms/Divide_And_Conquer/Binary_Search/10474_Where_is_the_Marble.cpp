#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q, l, r, m, x, Case = 0;
    bool b;
    while(cin >> N >> Q, (N || Q)){
    vector<int> L(N);
    for(int i = 0; i < N; ++i) cin >> L[i];
    sort(L.begin(), L.end());
    cout << "CASE# " << ++Case << ":\n";
    while(Q--) {
        cin >> x;
        b = false;
        l = -1;
        r = N;
        while(r > l + 1) {
            m = (l + r) / 2;
            if(L[m] < x) l = m;
            else r = m;
        }
        if(r <  N && L[r] == x) cout << x << " found at " << r + 1 << "\n";
        else cout << x << " not found\n";
    }
    }


    return 0;
}