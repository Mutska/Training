#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    while (getline(cin, s)) {
        if (s[0] == '_') break;
        int p = 1, code = 0;
        for(int i = 9; i > 1; --i) {
            if (s[i] != '.'){
                if (s[i] == 'o') code += p;
                p *= 2;
            }
        }
        cout << (char) code;
    }
    return 0;
}