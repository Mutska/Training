#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double c;
bool good(double x) {
    return (x*x + sqrt(x)) <= c;
}
int main() {
    cin >> c;
    double l = 0; //l is good
    double r = sqrt(c); //r is bad
    for(int t = 0; t < 100; ++t) {
        double m = (l + r) / 2.0;
        if(good(m)) l = m;
        else r = m;
    }
    cout << setprecision(20) << l << "\n";

}