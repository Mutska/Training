#include <string>
#include <iostream>


using namespace std;

char c[200];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string p_alphabet, s_alphabet, text;
    int t, m = 0;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        if(m++ > 0) cout << "\n";
        for(int i = 0; i < 200; ++i) c[i] = '\n';
        getline(cin, p_alphabet);
        getline(cin, s_alphabet);
        cout << s_alphabet << "\n";
        cout << p_alphabet << "\n";
        int n = p_alphabet.size();
        for(int i = 0; i < n; ++i) c[p_alphabet[i]] = s_alphabet[i];
        while(getline(cin, text)) {
            if (text.empty()) break;
            n = text.size();
            for(int i = 0; i < n; ++i) {
                if (c[text[i]] == '\n') cout << text[i];
                else cout << c[text[i]];
            }
            cout << "\n";
        }
    }



    return 0;
}