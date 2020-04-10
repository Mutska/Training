#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int index, sum,  num, qu, query, minimum, closest,
        N, M, n, m, i, j, numbers[1000], Case = 1;

    while(cin >> N, (N || 0)) {
        cout << "Case " << Case++ << ":\n";        
        n = N;
        index = 0;
        while(n--)
            cin >> num, numbers[index++] = num;
        cin >> M;
        m = M;
        while(m--) {
            minimum =  sum = closest = INT32_MAX;
            cin >> qu;
            for(i = 0; i < N; i++) {
                for(j = 0; j < N; j++) {
                    if(i != j) {
                        closest = abs(qu - (numbers[i] + numbers[j]));
                        if(closest <  minimum) {
                            minimum = closest;
                            sum = numbers[i] + numbers[j];
                        }
                    }
                }
            }
            cout << "Closest sum to " << qu << " is " << sum << ".\n";
                    
        }

    }






    return 0;
}