#include <iostream>
#include <string>
#include <map>
using namespace std;



int main(){
    int T, N, K;
    int Case = 0;
    string s;
    cin >> T;
    while(T--) {
        map<char, int> c;
        for(int i = 65; i < 91; ++i) c[(char)i] = 0;
        int count = 0;
        cin >> N >> K >> s;
        for(int i = 0; i < N; ++i) {
            for(int j = 1; j <= K; ++j) {
                if(i - j < 0) break;
                if(s[i] == s[i - j] && c[s[i]] != 1) {
                    ++count;
                    c[s[i]] = 1;
                }
            }
            c[s[i]] = 0;
        }
        cout << "Case " << ++Case << ": " << count << "\n";


    }




    return 0;
}