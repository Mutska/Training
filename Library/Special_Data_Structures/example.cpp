struct segtree {
    int size;
    vector<int> sums;
    vector<int> lazy;

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        sums.assign(2*size, 0);
        lazy.assign(2*size, -1);
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
        if(lazy[x] != -1) {
                if(lazy[x] == 0) {
                    sums[x] = 0;
                    if(rx - lx != 1) {
                        lazy[2*x+1] = 0;
                        lazy[2*x+2] = 0;
                    }
                } else if(lazy[x] == 1) {
                    sums[x] = (rx - lx);
                    if(rx - lx != 1) {
                        lazy[2*x+1] = 1;
                        lazy[2*x+2] = 1;
                    }
                } else if(lazy[x] == -2) {
                    sums[x] = (rx-lx) - sums[x];
                    if(rx - lx != 1) {
                        lazy[2*x+1] = f[lazy[2*x + 1]];
                        lazy[2*x+2] = f[lazy[2*x + 2]];
                    }
                }
                lazy[x] = -1;
        }
    }

    void set(int i, int j, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(lx >= j || i >= rx) return;
        if(lx >= i && rx <= j) {
                if( v == 0) {
                    sums[x] = 0;
                    if(rx - lx != 1) {
                        lazy[2*x+1] = 0;
                        lazy[2*x+2] = 0;
                    }
                } else if(v == 1) {
                    sums[x] = (rx - lx);
                    if(rx - lx != 1) {
                        lazy[2*x+1] = 1;
                        lazy[2*x+2] = 1;
                    }
                } else if( v ==  -2) {
                    sums[x] = (rx-lx) - sums[x];
                    if(rx - lx != 1) {
                        lazy[2*x+1] = f[lazy[2*x+1]];
                        lazy[2*x+2] = f[lazy[2*x+2]];
                    }
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
