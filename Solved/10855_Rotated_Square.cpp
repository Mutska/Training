#include <iostream>
#include <vector>

using namespace std;

void rotateVector(vector<string> & mat) {
        int N = mat.size();
        for (int x = 0; x < N / 2; x++) { 
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < N - x - 1; y++) { 
            // Store current cell in 
            // temp variable 
            char temp = mat[x][y]; 
  
            // Move values from right to top 
            mat[x][y] = mat[y][N - 1 - x]; 
  
            // Move values from bottom to right 
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
  
            // Move values from left to bottom 
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
  
            // Assign temp to left 
            mat[N - 1 - y][x] = temp; 
        } 
    } 

}

int main() {
    string temp;
    int N, n, G0, G90 , G180, G270, current, S, s, pos;
    bool check;
    while(cin >> N >> n , (N || n)) {
        G0 = G90 = G180 = G270 = 0;
        vector<string> SQUARE;
        vector<string> square;
        while(N--) {
            cin >> temp;
            SQUARE.emplace_back(temp);
        }
        while(n--) {
            cin >> temp;
            square.emplace_back(temp);
        }
        S = SQUARE.size();
        s = square.size();
        if(s == S) {
            if(SQUARE == square) ++G0;
            rotateVector(square);
            if(SQUARE == square) ++G270;
            rotateVector(square);
            if(SQUARE == square) ++G180;
            rotateVector(square);
            if(SQUARE == square) ++G90;
            cout << G0 << " " << G90 << " " << G180 << " " << G270 << "\n";
        } else if(s == 1) {
           char character = square[0][0]; 
           for(int i = 0; i < S ; ++i) 
               for(int j = 0; j < S; ++j) 
                   if(SQUARE[i][j] == character)++G0;
           G90 = G180 = G270 = G0;
           cout << G0 << " " << G90 << " " << G180 << " " << G270 << "\n";
        } else {
            current = 0;
            check  = true;
            vector<vector<int>> positions(s, vector<int>());
            pos = SQUARE[0].find(square[0]);
            cout << "pos in row 0 is: " << pos << "\n";
            while(pos != string::npos) {
               positions[0].emplace_back(pos);
               pos = SQUARE[0].find(square[0], pos + 1);
            }
            while(current > 0) {
                
            }
            pos = SQUARE[0].find(square[0]);
            cout << pos << "\n";
            while(pos != string::npos) {
               positions[0].emplace_back(pos);
               pos = SQUARE[0].find(square[0], pos + 1);
            }
            for(int & p: positions[0]) cout << p << " ";
            cout << "\n";
            temp = SQUARE[1].substr(positions[0][0], s);
            cout << temp << "\n";
            if(temp == square[1])
                cout << "LO ENCONTRE\n";

       }
    }
    return 0;

}