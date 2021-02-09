#include <iostream>
#include <cstring>
//Spoj
//Bottom Up Approach
int N;


using namespace std;
long long monster[10010];
long long memo[10010];
int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int T,Cases = 0;
    cin >> T;
    while(T--) {
       cin >> N;
       for(int i = 0; i < N; ++i) cin >> monster[i];
       memo[0] = 0; //no houses
       memo[1] = monster[0];//If I only have one house, only choice is to rob that hause
       if(N == 0) cout << "Case " << ++Cases << ": " << 0 << "\n"; //no houses
       if(N == 1) cout << "Case " << ++Cases << ": " << memo[1] << "\n";
       if(N > 1) {
           memo[2] = max(monster[0], monster[1]); //If I only  have two houses, rob the richest house
           //In order to rob the 3rd house, need to have robbed the first one
           //If not, we must have only robbed 2nd house, Choose max of these two actions
           for(int i = 3; i <= N; ++i) memo[i] = max(memo[i-2] + monster[i-1], memo[i-1]);
           cout << "Case " << ++Cases << ": " << memo[N] << "\n";
       }
    }

    return 0;
}

