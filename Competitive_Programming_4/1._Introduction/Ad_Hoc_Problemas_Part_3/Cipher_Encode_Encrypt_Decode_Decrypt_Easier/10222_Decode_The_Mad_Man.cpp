#include <string>
#include <iostream>

using namespace std;

char c[200];

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    c['e'] = 'q';
    c['r'] = 'w';
    c['t'] = 'e';
    c['y'] = 'r';
    c['u'] = 't';
    c['i'] = 'y';
    c['o'] = 'u';
    c['p'] = 'i';
    c['['] = 'o';
    c[']'] = 'p';

    c['d'] = 'a';
    c['f'] = 's';
    c['g'] = 'd';
    c['h'] = 'f';
    c['j'] = 'g';
    c['k'] = 'h';
    c['l'] = 'j';
    c[';'] = 'k';
    c['\''] = 'l';

    c['c'] = 'z';
    c['v'] = 'x';
    c['b'] = 'c';
    c['n'] = 'v';
    c['m'] = 'b';
    c[','] = 'n';
    c['.'] = 'm';

    string s;
    while(getline(cin, s)) {
        for(char &cc: s) {
            if (isspace(cc)) cout << cc;
            else cout << c[tolower(cc)];
        }
        cout << "\n";
    }
    return 0;
}