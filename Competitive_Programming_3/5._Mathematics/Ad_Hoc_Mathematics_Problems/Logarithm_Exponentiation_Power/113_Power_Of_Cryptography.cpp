#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;


int main() {
    long double n, p;

    while(cin >> n >> p) {
        cout << fixed << setprecision(0) <<  powl(p, (1.0/n)) << "\n";
    }



    return 0;
}