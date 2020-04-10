#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    tuple<string, int, int> database[10000];
    int T, D, Q, L, H, index, price, number, queries, count;
    string maker, M;
    cin >> T;
    while(T--) {
        cin >> D;
        index = 0;
        while(D--) {
            cin >>  M >> L >> H;
            database[index++] = make_tuple(M, L, H);
        }
        cin >> queries;
        while(queries--) {
            cin >> price;
            count = 0;
            for(int i = 0; i < index; i++) {
                if(price >= get<1>(database[i]) && price <= get<2>(database[i]))
                    if(count == 0)
                        maker = get<0>(database[i]), count++;
                    else 
                        count++;
            }
            if(count == 0 || count > 1) cout << "UNDETERMINED\n";
            if(count == 1) cout << maker << "\n";
        }
        if(T) cout << "\n";
    }



    return 0;
}