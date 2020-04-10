#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, used, tmp;
    bool noSolution, first = true;
    while(cin >> N, (N || 0)) {
        if(!first) cout << "\n";
        first = false;
        noSolution = true;
        for(int fghij = 1234; fghij <= 98765 / N; fghij++) {
            int abcde = fghij * N;
            used =  (fghij < 10000);
            tmp = abcde; while(tmp) {used  |= 1 << (tmp % 10); tmp /= 10; }
            tmp = fghij; while(tmp) {used  |= 1 << (tmp % 10); tmp /= 10; }
            if(used == (1 << 10) - 1) {
                cout << setfill('0') << setw(5)  << abcde;
                cout << " / ";
                cout << setfill('0') << setw(5) << fghij;
                cout << " = " << N << "\n";
                noSolution = false;
            }
        }
        if(noSolution)
            cout << "There are no solutions for " << N << ".\n";

    }

}