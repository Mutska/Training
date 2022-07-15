#include <string>
#include <iostream>
#include <sstream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t, decimal, hexadecimal, b1, b2;
    cin >> t;
    while(t--) {
        cin >> decimal;
        stringstream ss;
        ss << decimal;
        ss >> hex >> hexadecimal;
        b1 = __builtin_popcount(decimal);
        b2 = __builtin_popcount(hexadecimal);
        cout << b1 << " " << b2 << "\n";
    }
    return 0;
}