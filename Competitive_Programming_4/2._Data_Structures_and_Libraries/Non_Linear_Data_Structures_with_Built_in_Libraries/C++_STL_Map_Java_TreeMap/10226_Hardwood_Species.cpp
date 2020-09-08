#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, count;
    map<string, int> forest;
    string tree;
    cin >> T;
    cin.ignore();
    cin.ignore();
    while (T--) {
        forest.clear();
        count = 0;
        while(1) {
            getline(cin, tree);
            if(tree.size() == 0) {
                for(auto it = forest.begin(); it != forest.end(); it++) 
                    cout << it->first << " " << setprecision(4) << fixed << (double) it->second / (double) count * 100.0 << "\n"; 
                break;
            }else{
                forest[tree]++;
                count++;
            }
        }
        if(T > 0) cout << "\n";

    }


    return 0;
}