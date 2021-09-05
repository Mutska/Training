#include <string>
#include <iostream>

using namespace std;

int c[200];

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    c['A'] = 2;
    c['B'] = 2;
    c['C'] = 2;
    c['D'] = 3;
    c['E'] = 3;
    c['F'] = 3;
    c['G'] = 4;
    c['H'] = 4;
    c['I'] = 4;
    c['J'] = 5;
    c['K'] = 5;
    c['L'] = 5;
    c['M'] = 6;
    c['N'] = 6;
    c['O'] = 6;
    c['P'] = 7;
    c['Q'] = 7;
    c['R'] = 7;
    c['S'] = 7;
    c['T'] = 8;
    c['U'] = 8;
    c['V'] = 8;
    c['W'] = 9;
    c['X'] = 9;
    c['Y'] = 9;
    c['Z'] = 9;
    string s;
    while(cin >> s) {
        for(char &cc: s)
            if (cc == '1' || cc == '-') cout << cc;
            else cout << c[cc];
        cout << "\n";
    }
    return 0;
}