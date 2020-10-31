#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> k;
    for(int i = 0; i < k; ++i) {
        int x,y;
        cin >> x >> y;
        //Closest to the left
        int l = -1; //a[l] <= x
        int r = n; //a[r] > x
        while(r > l + 1) {
            int m  = (l + r) / 2;
            if(a[m] <= y) {
                l = m;
            } else {
                r = m;
            }
        }
        int L = l + 1;
        //Closest to the right
        l = -1; //a[l] < x
        r = n; //a[r] >= x
        while(r > l + 1) {
            int m  = (l + r) / 2;
            if(a[m] < x) {
                l = m;
            } else {
                r = m;
            }
        }
       int R = r + 1;
       if(L != 0 && R != n + 1) {
           cout << (L - R) + 1 << " ";
       } else if(L == 0 || R == n + 1) {
           cout << 0 << " ";
       }
    }
    cout << "\n";

    return 0;
}