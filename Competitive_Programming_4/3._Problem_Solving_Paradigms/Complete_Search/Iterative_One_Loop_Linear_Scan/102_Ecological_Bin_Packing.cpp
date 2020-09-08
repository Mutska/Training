#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int b1, b2, b3, g1, g2, g3, c1, c2, c3;
    while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3) {
        map<string, long long int> mapping;
        vector<string> res;
        mapping["BCG"] = b2 + b3 + c1 + c3 + g1 + g2;
        mapping["BGC"] = b2 + b3 + g1 + g3 + c1 + c2;
        mapping["CBG"] = c2 + c3 + b1 + b3 + g1 + g2;
        mapping["CGB"] = c2 + c3 + g1 + g3 + b1 + b2;
        mapping["GBC"] = g2 + g3 + b1 + b3 + c1 + c2;
        mapping["GCB"] = g2 + g3 + c1 + c3 + b1 + b2;
        auto it = mapping.begin();
        long long int minimum = it -> second;
        it++;
        for(it ; it != mapping.end(); it++) 
            minimum = min(minimum, it->second);
        for(it = mapping.begin(); it != mapping.end(); it++)
            if(it->second == minimum) res.push_back(it->first);
        sort(res.begin(), res.end());
        cout << res[0] << " " << minimum << "\n"; 

    }


    return 0;
}