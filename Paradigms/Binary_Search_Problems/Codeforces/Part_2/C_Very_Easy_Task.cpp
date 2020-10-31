#include <iostream>
#include <vector>


using namespace std;

long long n, x, y;
bool good(long long t) {
    //cout << "current suff is: " << (x/t) + (y/t) << "\n";
    t -= min(x,y);
    if(t < 0) return 0;
    return (t/x) + (t/y) + 1 >= n;
}

int main() {
    cin >> n >> x >> y;
    long long l = 0; //l is bad;
    long long r = 1; //r is good;

    while(!good(r)) r *= 2;
    //cout << "R is: " << r << "\n";
    while(r > l + 1) {
        long long m = (l + r) / 2;
        if(good(m)) r = m;
        else l = m;
    }
    cout <<  r << "\n";
    return 0;
}