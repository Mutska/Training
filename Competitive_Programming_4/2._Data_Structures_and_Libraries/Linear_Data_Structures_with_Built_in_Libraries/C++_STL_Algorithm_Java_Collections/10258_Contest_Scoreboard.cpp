#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <cstring>

using namespace std;

bool mysort(const tuple <int, int, int>& a, const tuple <int, int, int>& b) {
        if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b))
            return get<0>(a) < get<0>(b);
        if (get<1>(a) == get<1>(b))
            return get<2>(a) < get<2>(b);
        return get<1>(a) > get<1>(b);
}

int main () {
    vector <tuple<int,int,int>> results;
    map<int, map <int, int>> penalties;
    map<int, map <int, int>> done;
    int T, team, problem, time;
    char tokens[100], *token;
    bool flag;
    string L;
    cin >> T;
    getchar();
    getchar();
    while (T--) { 
        results.clear();
        penalties.clear();
        done.clear();
        while (1) {
            fgets(tokens, 100, stdin);
            tokens[(int)strlen(tokens) -1 ] = 0;
            if((int)strlen(tokens) == 0) break;
            int i = 1;
            L.clear();
            for (token = strtok(tokens," "); token ; token = strtok(NULL, " ")){
                if (i == 1) team = stoi(token);
                if (i == 2) problem = stoi(token);
                if (i == 3) time = stoi(token);
                if (i == 4) L.append(token);
                i++;
            }
            flag = false;
            int index_team = -1;
            for (int i = 0; i < (int) results.size(); i++) {
                if (get<0>(results[i]) == team) {
                    flag = true;
                    index_team = i;
                    break;
                }
            }
            if(L[0] != 'I' && L[0] != 'C')
                if(!flag)
                    results.push_back({team, 0,0});
            if (L[0] == 'I') {
                penalties[team][problem] += 20;
                if(!flag)
                    results.push_back({team, 0, 0});
            }
            if (L[0] == 'C') {
                if (!flag) {
                    results.push_back({team, 1, time + penalties[team][problem]});
                    done[team][problem] = 1;   
                }
                else {
                    if (done[team][problem] == 1) continue;
                    get<1>(results[index_team])++;
                    get<2>(results[index_team]) += penalties[team][problem];
                    get<2>(results[index_team]) += time;
                    done[team][problem] = 1;
                }
            }
       }   
         sort(results.begin(),results.end(), mysort);
         for(int i = 0; i < (int) results.size(); i++) {
                cout << get<0>(results[i]) << " "
             << get<1>(results[i]) << " "
             << get<2>(results[i]) << endl;
        }
        if(T) cout << endl;
    }

    return 0;
}