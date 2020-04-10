#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {  
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sequence[10000], mark[10001], N, M, n, index;
    string NS;
    bool isSequence;
    while(cin >> NS) {
        if(NS == "0") break;
        N = stoi(NS.substr(0,NS.size() - 1));
        M = N;
        index = 0;
        isSequence = false;
        while(N--) 
            cin >> n, sequence[index++] = n;
        for(int i = 0; i < M; i++) {
            if(i == M - 2) break;
            fill(mark, mark + M, 0);
            for(int m = 0; m <= i; m++) mark[sequence[m]] = 1;
            for(int j = i + 1; j < M ; j++) {
                mark[sequence[j]] = 1;
                //cout << "Pair is: " << sequence[i] << " "  << sequence[j] << "\n";
                int constant = abs(sequence[i] - sequence[j]);
                int a = abs(sequence[j] - constant);
                int b = sequence[j] + constant;
                //cout << "Constant is: " << constant << "\n";
                //cout << "A is: " << a << "\n";
                //cout << "B is: " << b << "\n";
                int byCheck;
                if(a == sequence[i]) byCheck = b;
                if(b == sequence[i]) byCheck = a;
                if(abs(sequence[j] - byCheck) == constant && byCheck < M && !mark[byCheck] ) {
                    isSequence = true;
                    break;
                    //cout << "THERE IS A ARITHMETIC SEQUENCE: \n";
                    //cout << sequence[i] << " " << sequence[j] << " " << byCheck << "\n";
                }
            }
            if(isSequence) break;  
        } 
        if(isSequence) cout << "no\n";
        else cout << "yes\n";

    }





    return 0;
}