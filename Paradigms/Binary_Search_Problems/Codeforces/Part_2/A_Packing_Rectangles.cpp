#include <iostream>
#include <vector>


using namespace std;

long long w, h, n;
bool good(long long x) {
    return (x/w) *(x/h) >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> w >> h >> n;

    long long l = 0; //l is bad;
    long long r = 1; //r is good;

    while(!good(r)) r *= 2;

    while(r > l + 1) {
        long long m = (l + r) / 2;
        if(good(m)) r = m;
        else l = m;
    }
    cout <<  r << "\n";
    return 0;
}