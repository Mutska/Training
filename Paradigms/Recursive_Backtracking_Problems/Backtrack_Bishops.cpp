#include <iostream>
#include <vector>

using namespace std;

int chessboard[4][4] = {0};

vector<pair<int, int>> bye;
vector<pair<int, int>> Bishops;
int lineCounter; //global variables default values of 0 for ints

bool canPlace(int r, int c) {
    if(chessboard[r][c]) return false;
    for(int prev = 0; prev < (int) Bishops.size(); ++prev) 
        if(abs(Bishops[prev].first - r) == abs(Bishops[prev].second-c))
            return false;
    chessboard[r][c] = 1;
    return true;
}
//bool notAlready()

void backtrack(int n) {
    cout << "current n is: " << n << "\n";
    if(n == 4) { 
        cout << ++lineCounter << " ";
        for(auto &b: Bishops) {
            cout << "(" << b.first << "," << b.second << ") ";
        }
        cout << "\n";
        //chessboard[Bishops.back().first][Bishops.back().second] = 0;
        bye.push_back(Bishops.back());
        Bishops.pop_back();
        return;
    }
    for(int i = 0; i < 4; ++i) { 
        for(int j = 0; j < 4; ++j) {
        if(canPlace(i, j)) {     
            Bishops.push_back({i, j});
            cout << "PUSHING: " << "(" << i << "," << j << ")\n";
            cout << "WITH N: " << n  << "\n";
            backtrack(n + 1);
            }
        }
    }
    if(Bishops.empty()) return;
    for(auto& b: bye) chessboard[b.first][b.second] = 0;
    int i = Bishops.back().first;
    int j = Bishops.back().second;
    chessboard[i][j] = 1;
    Bishops.pop_back();
    backtrack(n-1);
    chessboard[i][j] = 0;

}

int main() {

    lineCounter = 0;
    backtrack(0);
    return 0;
}

