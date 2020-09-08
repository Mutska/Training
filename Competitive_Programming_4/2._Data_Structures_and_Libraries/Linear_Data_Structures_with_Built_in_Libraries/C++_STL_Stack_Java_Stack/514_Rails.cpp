#include <iostream>
#include <stack>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> station;
    int n, rail, index, temp, rails[1001], order[10001]; 
    while(cin >> n, (n || 0)) {
        temp = n;
        iota(order, order + n + 1, 0);
        while(1) {
            cin >> rail;
            if(rail == 0) break;
            rails[1] = rail;
            n = temp - 1;
            index = 2; 
            while(n--) {
                cin >> rail;
                rails[index++] = rail;
            }
            int j = 1;
            int i = 0;
            while(1)  {
                i++;
                if(i > temp) break;
               station.push(order[i]);
               if(!station.empty() &&  station.top() == rails[j]) {
                   station.pop();
                   j++;
                   while(1) {
                       if(!station.empty() && station.top() == rails[j])
                        station.pop(), j++;
                        else
                            break;
                   }
               }
            }
            (station.empty()) ? cout << "Yes\n" : cout << "No\n";
            while(!station.empty()) station.pop();
        }
        cout << "\n";
    }
    return 0;
}