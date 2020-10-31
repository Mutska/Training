#include <iostream>

using namespace std;

int row[4] = {0}, a, b, lineCounter; 

bool canPlace(int r, int c) {
    for(int prev = 0; prev < c; ++prev) 
        if((abs(row[prev] - r) == abs(prev-c)))
            return false;
    return true;
}

void backtrack(int c) {
    if(c == 4) { 
        cout << ++lineCounter << " " << row[0] + 1;
        for(int j = 1; j < 4; ++j) cout << " " << row[j] + 1;
        cout << "\n";
        return;
    }
    for(int r = 0; r < 4; ++r) { 
        if(canPlace(r, c))      
            row[c] = r, backtrack(c + 1);
    }
}

int main() {

    lineCounter = 0;
    backtrack(0);
    return 0;
}

