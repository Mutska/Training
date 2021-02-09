#include <iostream>
#include <cstring>
#include <queue>


using namespace std;
int  R, C;
int  sr, sc; //start coordinates
int  r, c; //current coordinates

queue<int> rq; //row queue
queue<int> cq; //column queue

char dungeon [1005][1005];
int dist[1005][1005];

//north, south, east, west,
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};


void explore_neighbours(int r, int c){
    for(int i = 0; i < 4; ++i){
        int rr = r + dr[i];
        int cc = c + dc[i];
        //Invalid locations
        if(rr < 0 || cc < 0) continue;
        if(rr >= R || cc >= C) continue;
        //Skip visited locations or blocked cells
        if(dist[rr][cc] != -1) continue;
        if(dungeon[rr][cc] == '#') continue;
        rq.push(rr);
        cq.push(cc);
        dist[rr][cc] = dist[r][c] + 1;
    }

    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> R >> C;
        memset(dist, -1, sizeof dist);
        vector<pair<int, int>> coordinates;
        vector<int> exits_distance;
        while(!rq.empty())cq.pop(), rq.pop();
        for(int r = 0; r < R; ++r){
            for(int c = 0; c < C; ++c){
                cin >> dungeon[r][c];
                if(dungeon[r][c] == 'J') {sr = r; sc = c;}
                if(r == 0 || c == 0 || r == R - 1 || c == C -1 ){
                    if(dungeon[r][c] == '.' ) {
                        coordinates.emplace_back(r,c);
                    }
                }
                if(dungeon[r][c] == 'F') {
                    rq.push(r);
                    cq.push(c);
                    dist[r][c] = 0;
                }
            }
        }
        if(R == 1 && C == 1){
            cout << "1\n";
            continue;
        }
        if(sr == 0 || sc == 0 || sr == R - 1 || sc == C -1 ){
            cout << "1\n";
            continue;
        }
        if(coordinates.size() == 0) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        while(rq.size() > 0){
            r = rq.front(); rq.pop();
            c = cq.front(); cq.pop();
            explore_neighbours(r, c);
        }
      //for(int r = 0; r < R; ++r){
      //    for(int c = 0; c < C; ++c){
      //        if(dist[r][c] != -1) cout << dist[r][c];
      //        else cout << dungeon[r][c];
      //    }
      //    cout << "\n";
      //}
        for(auto p: coordinates){
            int d = dist[p.first][p.second];
            exits_distance.emplace_back(d);
        }
        while(!rq.empty())cq.pop(), rq.pop();
        rq.push(sr);
        cq.push(sc);
        memset(dist, -1, sizeof dist);
        dist[sr][sc]  = 0;
        while(rq.size() > 0){
            r = rq.front(); rq.pop();
            c = cq.front(); cq.pop();
            explore_neighbours(r, c);
        }
      // cout << "\n\n\n";
      // for(int r = 0; r < R; ++r){
      //          for(int c = 0; c < C; ++c){
      //              if(dist[r][c] != -1) cout << dist[r][c];
      //              else cout << dungeon[r][c];
      //          }
      //          cout << "\n";
      // }
      // int minimum = INT32_MAX;
        int n = coordinates.size();
        for(int i = 0; i < n; ++i){
            int dist1 = dist[coordinates[i].first][coordinates[i].second];
            int dist2 = exits_distance[i];
            if(dist1 == -1 && dist2 == -1) continue;
            if(dist1 != -1 && dist2 == -1) minimum = min(minimum, dist1);
            if(dist1 != -1 && dist2 != -1)
                if(dist1 < dist2) minimum = min(minimum,dist1);
        }
        if(minimum != INT32_MAX) cout << minimum + 1 << "\n";
        else cout << "IMPOSSIBLE\n";

    }
    return 0;
}