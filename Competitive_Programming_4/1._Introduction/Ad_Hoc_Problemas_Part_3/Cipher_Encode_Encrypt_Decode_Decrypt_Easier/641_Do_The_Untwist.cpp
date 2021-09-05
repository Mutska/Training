#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int key, n, code;
    string ciphertext;
    char text[80];
    while(cin >> key) {
        if (key == 0) break;
        cin >> ciphertext;
        n = ciphertext.size();
        for(int i = 0; i < n; ++i) {
            if(ciphertext[i] == '.')    code = 27;
            else if(ciphertext[i] == '_')   code = 0;
            else code = ciphertext[i] - 'a' + 1;
            code = (code+i) % 28;
            if(code == 0)   code = '_';
            else if(code == 27) code = '.';
            else code = code - 1 + 'a';
            text[(key*i) % n] = code;
        }
        for(int i = 0; i < n; ++i) cout << text[i];
        cout << "\n";
    }
    return 0;
}