//2020-01-22 ID Codes by Mutska
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    string n;

    while(cin >> n) {
        if (n == "#") break;
        
        if (next_permutation(n.begin(), n.begin() + n.size()))
            cout << n << "\n";
        else
            cout << "No Successor\n";

    }

    return 0;
}
