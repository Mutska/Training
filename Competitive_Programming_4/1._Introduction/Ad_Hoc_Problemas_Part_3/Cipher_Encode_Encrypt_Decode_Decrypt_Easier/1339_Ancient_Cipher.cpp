#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    vector<int> ac, bc;
    while(cin >> a >> b){
        int n = a.size();
        ac.assign(26, 0);
        bc.assign(26, 0);
        for(int i = 0; i < n; ++i)  ac[a[i] - 'A']++, bc[b[i] - 'A']++;
        sort(ac.begin(), ac.end());
        sort(bc.begin(), bc.end());
        
        bool ok = true;
        for(int i = 0; i < 26; ++i)
            if (ac[i] != bc[i]){
                ok = false;
                break;
            }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}