#include <iostream>
#include <vector>


using namespace std;


long long combinations(int n, int k){
    long long C = 1;
    if(k > n-k) k = n - k;
    for(int i = 0; i < k;++i){
        C *= (n - i);
        C /= (1 + i);
    }
    return C;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    long long MC;
    while(cin >> n){
        cin >> k;
        vector<int> powers(k);
        for(int i = 0; i < k; ++i) cin >> powers[i];
        MC = 1;
        int N = powers[0];
        int K = powers[0];
        for(int i = 1; i < k; ++i){
            N += powers[i];
            K = powers[i];
            MC *= combinations(N, K);
        }
        cout << MC << "\n";
    }



    return 0;
}