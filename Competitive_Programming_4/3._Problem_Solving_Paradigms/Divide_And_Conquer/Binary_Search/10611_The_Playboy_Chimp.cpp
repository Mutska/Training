#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q, x;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> Q;
    while(Q--) {
        cin >> x;
        int l = -1;//a[l] < x
        int r = N;//a[r] >= x
        while(r > l + 1) {
            int m = (l + r) / 2;
            if(a[m] >= x)  r = m;
            else l = m;
        }
        if(l != -1) cout << a[l] << " ";
        else cout << "X ";
        l = -1; //a[l] <= x
        r = N; //a[r] > x

        while(r > l + 1) {
            int m = (l + r) / 2;
            if(a[m] <= x) l = m;
            else r = m;
        }
        if(r != N) cout << a[r] << "\n";
        else cout << "X\n";
    }






    return 0;
}