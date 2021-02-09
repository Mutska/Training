#include <iostream>
#include <cstring>
#include <queue>


using namespace std;
int L, R, C;
int sl, sr, sc; //start coordinates
int l, r, c; //current coordinates

queue<int> lq; //level queue
queue<int> rq; //row queue
queue<int> cq; //column queue
int move_count;

int nodes_left_in_layer;
int nodes_in_next_layer;

bool reachend_end;
char dungeon [40][40][40];
bool visited [40][40][40] = {false};

//north, south, east, west, up, down directions;
int dl[] = {0, 0, 0, 0, 1, -1};
int dr[] = {-1, 1, 0, 0, 0, 0};
int dc[] = {0, 0, 1, -1, 0, 0};


void explore_neighbours(int l, int r, int c){
    for(int i = 0; i < 6; ++i){
        int ll = l + dl[i];
        int rr = r + dr[i];
        int cc = c + dc[i];
        //Invalid locations
        if(ll < 0 || rr < 0 || cc < 0) continue;
        if(ll >= L || rr >= R || cc >= C) continue;
        //Skip visited locations or blocked cells
        if(visited[ll][rr][cc]) continue;
        if(dungeon[ll][rr][cc] == '#') continue;
        
        lq.push(ll);
        rq.push(rr);
        cq.push(cc);
        visited[ll][rr][cc] = 1;
        ++nodes_in_next_layer;
    }

    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> L >> R >> C, (L || R || C)){
        memset(visited, 0, sizeof visited);
        while(!lq.empty()) lq.pop(), cq.pop(), rq.pop();
        for(int l = 0; l < L; ++l){
            for(int r = 0; r < R; ++r){
                for(int c = 0; c < C; ++c){
                    cin >> dungeon[l][r][c];
                    if(dungeon[l][r][c] == 'S') sl = l, sr = r, sc = c;
                }
            }
            cin.ignore();
        }
        move_count = 0;

        nodes_left_in_layer = 1;
        nodes_in_next_layer = 0;

        reachend_end = false;

        visited[sl][sr][sc] = true;


        lq.push(sl);
        rq.push(sr);
        cq.push(sc);

        while(lq.size() > 0){
            l = lq.front(); lq.pop();
            r = rq.front(); rq.pop();
            c = cq.front(); cq.pop();
            if(dungeon[l][r][c] == 'E'){
                reachend_end = true;
                break;
            }
            explore_neighbours(l, r, c);
            --nodes_left_in_layer;
            if(nodes_left_in_layer == 0) {
                nodes_left_in_layer = nodes_in_next_layer;
                nodes_in_next_layer = 0;
                ++move_count;
            }
            if(reachend_end) break;
        }
        if(reachend_end) cout << "Escaped in " << move_count << " minute(s).\n";
        else cout  << "Trapped!\n";
     // for(int l = 0; l < L; ++l){
     //     for(int r = 0; r < R; ++r){
     //         for(int c = 0; c < C; ++c) {
     //          if(visited[l][r][c]) cout << "v";
     //          else cout  << dungeon[l][r][c];
     //         }
     //         cout << "\n";
     //     }
     //     cout << "\n\n";
     // }
                    
    }
    return 0;
}