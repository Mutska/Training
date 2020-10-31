#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct segtree {
    int size;
    vector<int> sums;
    vector<int> lazy;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size, 0);
        lazy.assign(2*size, 0);
    }
    void build(vector<int> &a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x + 1, lx, m);
        build(a, 2*x + 2, m, rx);
        sums[x] = sums[2*x + 1] + sums[2*x + 2];
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);

    }
    
    void propagate(int x, int lx, int rx) {
        if(lazy[x] != 0) {
            sums[x] = (rx-lx)*lazy[x];
        }
        if(rx-lx != 1) {
            lazy[2*x+1] = lazy[x];
            lazy[2*x+2] = lazy[x];
        }
        lazy[x] = 0;
    }

    void set(int i, int j, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(lx >= j || i >= rx) return;
        if(lx >= i && rx <= j) {
            sums[x] = (rx-lx)*v;
            if(rx - lx != 1) {
                lazy[2*x+1] = v;
                lazy[2*x+2] = v;
            }
            return;
        }
        int m = (lx + rx) / 2;
        set(i, min(j, m), v, 2*x + 1, lx, m);
        set(max(i, m), j, v, 2*x + 2, m, rx);
        sums[x] = sums[2*x + 1] + sums[2*x+2];
    }

    void set(int i, int j, int v) {
        set(i, j, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if(lx >= r || l >= rx) return 0;
        propagate(x, lx, rx);
        if(lx >= l && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2*x + 1, lx, m);
        long long s2 = sum(l, r, 2*x + 2, m, rx);
        return s1 + s2;
    }

    long long sum(int l, int r ) {
        return sum(l, r, 0, 0, size);
    }

};


int main(){

    int n, m;
    segtree st;
    st.init(4);
    vector <int> a = {1,1,1,1};
    st.build(a);
    cin >> m;
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int i,j, v;
            cin >> i >> j >> v;
            st.set(i, j, v);
        }
        else {
            int l,r;
            cin >> l >> r;
            cout <<  st.sum(l, r) << "\n";
        }
    }

    return 0; 
}


