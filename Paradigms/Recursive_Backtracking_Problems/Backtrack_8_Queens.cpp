#include <iostream>

using namespace std;

int row[8] = {0}, a, b, lineCounter; //global variables default values of 0 for ints

bool canPlace(int r, int c) {
    for(int prev = 0; prev < c; ++prev) //check previous queens
        if(row[prev] == r || (abs(row[prev] - r) == abs(prev-c)))
            return false;
    return true;
}

void backtrack(int c) {
    if(c == 8) { //&& row[b] == a) { //a candidate sol
        cout << ++lineCounter << " " << row[0] + 1;
        for(int j = 1; j < 8; ++j) cout << " " << row[j] + 1;
        cout << "\n";
        return;
    }
    for(int r = 0; r < 8; ++r) { //try all posible row
        //if((c == b) && (r != a)) continue;  //early pruning;
        if(canPlace(r, c))      //can place a queen here?
            row[c] = r, backtrack(c + 1);//put here and recurse
    }
}

int main() {

    lineCounter = 0;
    backtrack(0);
    return 0;
}

