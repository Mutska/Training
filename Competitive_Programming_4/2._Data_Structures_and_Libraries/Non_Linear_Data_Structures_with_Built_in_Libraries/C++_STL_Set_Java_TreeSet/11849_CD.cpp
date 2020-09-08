#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   int N, M,  cd, result;

    while(cin >> N >> M, (N || M)) {
        set<int> cds;
        result = 0;
        while(N--) {
            cin >> cd;
            cds.insert(cd);
        }
        while(M--) {
            cin >> cd;
            if(cds.find(cd) != cds.end())
                result++;
        }
        cout << result << "\n";


    }
    return 0;
}