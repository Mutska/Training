#include <iostream>
#include <cmath>


using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    while(cin >> n >> k){
        long double digits = 0;
        for(int i = n - k + 1; i <= n; ++i) digits += log10((long double)i);
        for(int i = 1; i <= k; ++i) digits -= log10((long double) i);
        long long total = (long long) digits + 1;
        cout << total << "\n";
    }



    return 0;
}