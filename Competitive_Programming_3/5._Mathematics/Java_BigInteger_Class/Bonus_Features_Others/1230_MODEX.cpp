
#include <iostream>


using namespace std;

long long binary_exponentiation(long long B, long long P, long long M) {
    if(B == 0LL) return 0;
    if(P == 0LL && (1LL % M == 0)) return 0;
    B %= M;
    long long res = 1LL;
    while(P > 0) {
        if(P & 1LL)
            res = res * B % M;
        B  = B * B % M;
        P >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x, y, n;
    int c;
    cin >> c;
    while(c--){
        cin >> x >> y >> n;
        cout << binary_exponentiation(x, y, n) << "\n";
    }
    cin >> c;

}