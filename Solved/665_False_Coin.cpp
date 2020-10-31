#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M, N, K, Pi, id;
    string c;
    cin >> M;
    while(M--) {
        cin >> N >> K;
        vector<bool>coins(N, true);
        while(K--) {
            cin >> Pi;
            vector<int> ids;
            for(int i = 0; i < 2*Pi; ++i) {
                cin >> id;
                ids.emplace_back(id);
            }
            cin >> c;
            if(c == "=") 
                for(int &i : ids) coins[i - 1] = false;
           //else if(c == ">") 
           //    for(int i = Pi ; i < (int) coins.size(); ++i) coins[i] = false;
           //else if(c == "<") 
           //    for(int i = 0; i < Pi ; ++i) coins[i] = false;
        }
        int flag, pos, idx;
        flag = pos = idx =  0;
        bool f = true; 
        for(int i = 0; i < (int) coins.size(); ++i) {
            if(coins[i] == 1) ++flag;
            if(flag == 1 && f) {pos = i; f = false;}
            if(flag > 1 ) break;
        }
        if(flag == 1) cout << pos + 1<< "\n";
        else cout << "0\n";
        if(M)  cout << "\n";

    } 



    return 0;
}