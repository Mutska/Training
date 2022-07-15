#include <iostream>
#include <vector>

using namespace std;
int m, n;
int si, sj;
char M[9][9];
const string KEY= "@IEHOVA#"; 

string dir[7]; 
int d2[3] = {-1,0,1}; 
int d1[3] = {0,-1,0}; 
string directions[3] = {"left", "forth", "right"}; 

bool canMove(int j) {
  bool check = (si + d1[j] >= 0 && si + d1[j] < m) && (sj + d2[j] >= 0 && sj + d2[j] < n) ? 1: 0;
  return check;
}


void bt(int it){
    if (it == 7) {
        cout << dir[0];
        for (int i = 1; i < 7; ++i) cout << " " << dir[i];
        cout << "\n";
        return;
    }

    for(int j = 0; j < 3; ++j) {
          if (canMove(j)) {
                if (M[si + d1[j]][sj + d2[j]] == KEY[it + 1]){
                    si += d1[j];
                    sj += d2[j];
                    dir[it] = directions[j];
                    bt(it + 1);
                    si -= d1[j];
                    sj -= d2[j];
                }
          }
    }
}



int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  char g;

  while(T--){
    cin >> m >> n;
    cin.ignore();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> M[i][j];
        if (M[i][j] == '@') {
          si = i;
          sj = j;
        } 
      } 
      cin.ignore();
    }
    bt(0);
  }
  return 0;
}