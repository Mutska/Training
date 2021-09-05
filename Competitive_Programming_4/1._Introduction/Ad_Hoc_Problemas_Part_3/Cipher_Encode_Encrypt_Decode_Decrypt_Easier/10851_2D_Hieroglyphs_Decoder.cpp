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

    while(t--) {
        int c = 1;
        getline(cin, s);
        int n = s.size();
        vector<int> code(n - 2, 0);
        while(getline(cin, s)) {
            if (s.empty()) break;
            if (c < 9) {
                for(int i = 1; i < n - 1; ++i) {
                    if (s[i] == '\\') {
                        code[i-1] |= (1 << (c-1));
                    }
                }
            }
            ++c;
        }
        for(int i: code) cout << (char) i;
        cout << "\n";
    }




    return 0;
}