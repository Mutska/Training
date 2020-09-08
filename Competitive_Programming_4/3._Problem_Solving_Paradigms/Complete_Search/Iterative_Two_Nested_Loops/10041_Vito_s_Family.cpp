#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int T, index, N, size, actual, minimum;
    int relatives[500], r;

    cin >> T;
    while(T--) {
        cin >> N;
        size = N;
        index = 0;
        while(N--) {
            cin >> r;
            relatives[index++] = r;
        }
        minimum = INT32_MAX;
        for(int i = 0; i < size; i++) {
            actual = 0;
            for(int j = 0; j < size; j++) 
                actual += abs(relatives[i] - relatives[j]);
            minimum = min(actual, minimum);
        }
        cout << minimum << "\n";

    }



    return 0;
}