#include <iostream>
#include <bitset>

using namespace std;


int N, H;
string solution = "";
int ones = 0;
int zeros = 0;

bool canAdd(char bit){
    int counter = ones; 
    if (bit == '1') ++counter;
    if (counter > H) return false;
    if (bit == '0') ++counter;
    if (zeros > (N-H)) return false;
    return true;
}

void backtrack(){
    if (solution.size() == N){
        if (ones == H) cout << solution << "\n";
        return;
    }
    for(int i = 0; i < 2; ++i){
        char bit = i == 0 ? '0' : '1';
        if(canAdd(bit)) {
            solution += bit;
            if (bit == '1') ++ones;
            else ++zeros;
            backtrack();
            solution.pop_back();
            if (bit == '1') --ones;
            else --zeros;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d;
    cin >> d;
    while(d--){
        cin >> N >> H;
        backtrack();
        solution.clear();
        if(d) cout << "\n";
    }
    return 0;
}