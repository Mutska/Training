#include <iostream>
#include <vector>

using namespace std;

char c[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    c[0] = 'O';
    c[1] = 'I';
    c[2] = 'Z';
    c[3] = 'E';
    c[4] = 'A';
    c[5] = 'S';
    c[6] = 'G';
    c[7] = 'T';
    c[8] = 'B';
    c[9] = 'P';
    int t;
    cin >> t;
    string s;
    cin.ignore();
    int m = 0;
    while(t--) {
        if (m++ > 0) cout << "\n";
        while(getline(cin, s)) {
            if (s.empty()) break;
            int n = s.size();
            for(int i = 0; i < n; ++i) {
                int code = s[i] - '0';
                if (code >= 0 && code <= 9) cout << c[code];
                else cout << s[i];
            }
            cout << "\n";
        }
    }




    return 0;
}