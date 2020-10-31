#include <iostream>
#include <cmath>
#include <iomanip>

double p, q, r, s, t, u;

bool good(double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u >= 0;
}
double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

using namespace std;



int main() {

    double zero = 0;
    while(cin >> p >> q >> r >> s >> t >> u){
        double l = 0; //l is good
        double r = 1; //r is bad
        for(int i = 0; i < 50; ++i) {
            double m = (l + r ) / 2.0;
            if(good(m))  l = m;
            else r = m;
        }
        if(abs(f(l)) < 1e-5) cout << fixed << setprecision(4) << l << "\n";
        else cout << "No solution\n";
    }


    return 0;
}