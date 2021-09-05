#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, Case = 0;
    char dummy;
    cin >> T;
    string s;
    while(T--){
        cout << "Case " << ++Case << ": ";
        char A;
        bool num = false;
        int current = 0, total = 0;
        string number = "";
        cin >> s;
        int n = s.size();
        char c = s[0];
        for (int i = 0; i < n; ++i){
            if (isdigit(s[i])) number += s[i], num = true;
            if (isalpha(s[i]) && num || i == n-1) {
                //cout <<  "char to print is: " << c;
                //cout << " number of times is: " << number << "\n";
                num = false;
                int l = stoi(number);
                number = "";
                for(int i = 0; i < l; ++i) cout << c;
                c = s[i];
            }
        }
        cout << "\n";

    }


    return 0;
}