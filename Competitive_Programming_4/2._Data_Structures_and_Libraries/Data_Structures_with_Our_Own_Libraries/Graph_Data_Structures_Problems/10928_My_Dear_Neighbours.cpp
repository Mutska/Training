#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b) {
    return a.size() < b.size();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, P;
    string line, aux;
    cin >> T;

    while(T--) {
        cin >> P;
        vector<vector<int>> AL(P, vector<int>());
        cin.ignore();
        int index = 0;
        int current = 0;
        while(P--) {
            getline(cin, line);
            AL[current].emplace_back(++index);
            stringstream ss(line);
            while(ss >> aux)  AL[current].emplace_back(1);
            ++current;
        }
        stable_sort(AL.begin(), AL.end(), compare);
        int size = AL[0].size();
        cout << AL[0][0];
        for(int i = 1; i < (int) AL.size(); ++i) {
            if((int)AL[i].size() == size) cout << " " << AL[i][0];
            else break;
        }
        cout << "\n";
    }



return 0;
}