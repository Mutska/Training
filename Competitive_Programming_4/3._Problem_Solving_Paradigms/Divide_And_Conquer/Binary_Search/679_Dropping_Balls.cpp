#include <iostream>
#include <cmath>


using namespace std;

int FBT; //Full Binary Tree
int NODE;

void binary_search(int node, int balls) {
    int left = node * 2, right = node * 2 + 1;
    if (left < FBT && right < FBT) {
        if (balls%2==0) binary_search(right, balls/2); 
        else binary_search(left, balls/2 + 1);
    } else {
        NODE = node;
        return;
    }
}

int main() {
    int T, D, I;
    cin >> T;
    while (T--){
        cin >> D >> I;
        FBT = pow(2.0, D);
        binary_search(1, I);
        cout << NODE << "\n";
    }
    cin >> D;
    return 0;
}