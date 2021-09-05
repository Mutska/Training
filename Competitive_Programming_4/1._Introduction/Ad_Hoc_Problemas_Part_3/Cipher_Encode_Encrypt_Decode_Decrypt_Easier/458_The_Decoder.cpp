#include <string>
#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    string s;
    while(cin >> s) {
        for(char &c: s) {
            char r = c - '\a';
            cout << r;
        }
        cout << "\n";
    }
    return 0;
}