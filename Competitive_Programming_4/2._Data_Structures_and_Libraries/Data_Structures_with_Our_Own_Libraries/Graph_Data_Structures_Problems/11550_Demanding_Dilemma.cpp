#include <iostream>
#include <vector>
#include <map>

using namespace std;

int IM[8][28];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        map<pair<int, int>, int> multiedges;
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j)
                cin >> IM[i][j];
        bool good = true;
        for(int  i = 0; i < m; ++i) {
            int sum = 0; 
            int count = 0;
            int first, second;
            for(int j = 0; j < n; ++j) {
                if(IM[j][i] == 1) {
                    ++sum;
                    if(count == 0) {
                        first = j;
                        ++count;
                    } else if(count == 1) {
                        second = j;
                        ++count;
                    } 
                }
                if(sum > 2) break;   
            }
            if(sum != 2) {
                good = false;
                break;
            }
            pair<int, int> edge = {first, second};
            multiedges[edge]++;
        }
        if(good) {
            for(auto &m: multiedges) {
                if(m.second > 1) {
                    good = false;
                    break;
                }
            }
        }
        if(good) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}