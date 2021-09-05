#include <sstream>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    cin.ignore();
    cin.ignore();
    int m = 0;
    while(t--) {
        if (m > 0) cout << "\n";
        cout << "Case #" << ++m << ":\n";
        while(getline(cin, s)) {
            if (s.empty()) break;
            stringstream ss(s);
            vector<string> tokens;
            while(ss >> s) tokens.emplace_back(s);
            int n = tokens.size();
            int idx = 1;
            for(int i = 0; i < n; ++i) {
                if (tokens[i].size() < idx) continue;
                cout << tokens[i][idx - 1];
                ++idx;
            }
            cout << "\n";
        }
    }
    return 0;
}