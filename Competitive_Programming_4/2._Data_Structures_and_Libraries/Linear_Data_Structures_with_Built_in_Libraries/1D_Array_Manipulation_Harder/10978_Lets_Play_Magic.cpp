#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


int  main() {
    int N, mod;
    string card, number;
    vector<pair<int, string>> res;
    while(cin >> N, (N || 0)) {
        mod = N;
        int absolute, size, pos;
        absolute = 0;
        while(N--) {
            cin >> card >> number << "\n";
             size = number.size();
             absolute += number.size() ;
             pos = absolute % mod;
        }
    }

}