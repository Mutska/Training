#include <iostream>
#include <cstring>


using namespace std;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
    int n, k;
    while(cin >> n >> k, (n || k)){
        long long C = 1;
        if(k > n-k) k = n - k;
        for(int i = 0; i < k;++i){
            C *= (n - i);
            C /= (1 + i);
        }
        cout << C << "\n";
    }



    return 0;
}