#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool check(string &n) {
    map<char, int> check;
    for(int i = 0; i < (int)n.size(); ++i) {
        if(n[i] == '0') return false;
        if(check.count(n[i]) == 1) return false;
        check[n[i]] = 1;
    }
    return true;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> runners;
    for(int i = 10; i < 10000000; ++i) {
    string n = to_string(i);  
    if(!check(n)) continue;
    map<char, int> positions;
    for(auto &c: n) positions[c] = 0;
    int size = n.size();
    int index = 0;
    int passed = 0;
    int to = 0;
    bool run = false;

    while(1) {
        index = (index + to) % size;
        if(passed == size) {
        //cout << "last index is: " << index << "\n";
            if(index == 0) {
                run = true;
              for(auto &p: positions) {
                 if(p.second == 0) {
                     run = false;
                     break;
                 }
              }
            }
            break;
        }
       // cout << "I am current in the index: " << index << " with char: "<< n[index] << "\n";
        ++passed;
        //cout << "passed is: " << passed << "\n";
        if(positions[n[index]] == 1 && index != 0){
            run = false;
            break;
        } 
        positions[n[index]] = 1;
        to = (int) n[index] - 48;
        //cout << "to is: " << to << "\n";
    }
        if(run) runners.emplace_back(n);
    }
    int Case = 0;
    for(auto &r: runners) {
        //cout << "Case " << ++Case << ": " << r << "\n";
        cout << r << ",";
    }
    cout << "\n";


    return 0;
}