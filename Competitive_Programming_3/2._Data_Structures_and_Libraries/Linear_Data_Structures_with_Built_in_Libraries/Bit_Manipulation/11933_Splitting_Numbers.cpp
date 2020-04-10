#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    unsigned int n, centinel;
    unsigned a, b, count;
    while(cin >> n, (n || false)) {
        count  = 1;
        a = b = centinel =0;
        for(int i = 0; centinel <= n; i++) {
            centinel |= (1 << i);
            if((n & (1 << i)) && count % 2 != 0) {
               a |= (1 << i);
               count ++;
               continue;
            }
            if((n & (1 << i)) && count %2 == 0){
               b |= (1 << i);
               count ++;
               continue;
            }
        }
        cout << a << " " << b << "\n";

    } 

    return 0;
}