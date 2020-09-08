#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a,b)*b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, G, L, T;
    cin >> T;
    while(T--) {
       cin >> G >> L; 
       if(L%G) cout << "-1\n";
       else cout << G << " " << L << "\n";
    }


    return 0;
}