#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[30005];

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 1;
    for(int c = 0; c < 11; ++c){
        for (int i = coins[c]; i <= 30000; ++i) dp[i] += dp[i-coins[c]];
    }
    long double c, cc;
    while(cin >> c) {
        if(c == 0)  break;
        cc = c;
        c *= 100;
        long long cents = (long long) round(c);
        cout << right << setw(6) << fixed <<  setprecision(2) << cc << setw(17) << dp[cents] << "\n";
    }
    return 0;
}