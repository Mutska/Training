#include <iostream>
#include <vector>




using namespace std;

string code[10] = {" ", ".,?\"", "abc", "def",
                   "ghi", "jkl", "mno", "pqrs",
                   "tuv,", "wxyz"};


int Ni[101], Pi[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, L;
    cin >> t;
    while(t--) {
        cin >> L; 
        for(int i = 0; i < L; ++i) cin >> Ni[i];
        for(int i = 0; i < L; ++i) cin >> Pi[i];
        for(int i = 0; i < L; ++i) {
            cout << code[Ni[i]][Pi[i]-1];
        }
        cout << "\n";
    }
    return 0;
}