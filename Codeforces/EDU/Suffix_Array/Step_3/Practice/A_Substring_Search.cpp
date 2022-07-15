
#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &p, vector<int> &c){ 
    int n  = p.size();
        vector<int> cnt(n);
        for(auto x: c){
            cnt[x]++;
        }
        vector<int> p_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for(int i = 1; i < n; ++i){
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for(auto x: p){
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
        p = p_new;
}

int equal(int &m, string &x, string &s){
    //cout << "p is: " << m <<"\n";
    int n = x.size();
    int max_size = s.size();
    string a;
    if(n + m > max_size) a = s.substr(m);
    else a = s.substr(m, n);
    string b = x; 
   //cout << "a is: " << a <<"\n";
   //cout << "b is: " << b <<"\n";
   //cout << "-----------------------\n";
    if(a == b) return 0;
    if(a < b) return -1;
    if(a > b) return 1;
}


int main(){

    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    {
        //k = 0;
        vector<pair<char, int>> a(n);
        for(int i = 0; i < n; ++i) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0; i < n; ++i) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; ++i){
            if(a[i].first == a[i - 1].first){
                c[p[i]] = c[p[i-1]];
            } else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    //transitions k -> k + 1
    int k = 0;
    while((1 << k) < n){
        //k -> k + 1
        for(int i = 0; i < n; ++i){
            p[i] = (p[i] - (1 << k) + n) %n;
        }
        count_sort(p, c);
       c[p[0]] = 0;
       vector<int> c_new(n);
       c_new[p[0]] = 0;
       for(int i = 1; i < n; ++i){
           pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
           pair<int, int> now = {c[p[i]], c[(p[i]+ (1 << k)) % n]};
           if(now == prev){
               c_new[p[i]] = c_new[p[i-1]];
           } else{
               c_new[p[i]] = c_new[p[i-1]] + 1;
           }
       }
       c = c_new;
        ++k;
    }
   //for(int i = 0; i < n; ++i){
   //    cout << p[i] << " " << s.substr(p[i], n - p[i]) <<  "\n";
   //}
// for(int i = 0; i < n; ++i){
//     cout << p[i] << " ";
// }
    //cout << "n size is: " << n <<"\n";
    cin >> k;
    string x;
    while(k--){
        cin >> x;
        int l = -1; //a[l] <= x
        int r = n; //a[r] > x
        int cnt = 0;
        int first_index  = -9;
        int second_index = -9;
        while(r > l + 1){
            int m = (l + r) / 2;
            //cout << "m is: " << m << "\n";
            int cmp = equal(p[m], x, s);
            if(cmp == 0 || cmp == -1){
                l = m;
            } else{
                r = m;
            }
        }
        //cout << l + 1 << "\n";
        if(l > -1) {
            int cmp = equal(p[l], x, s);
            if(cmp == 0) first_index = l;
        }
        l = -1;
        r = n;
        while(r > l + 1){
            int m = (l + r) / 2;
            //cout << "m is: " << m << "\n";
            int cmp = equal(p[m], x, s);
            if(cmp == -1){
                l = m;
            } else{
                r = m;
            }
        }
       // cout << r + 1 << "\n";
        if(r < n) {
            int cmp = equal(p[r], x, s);
            if(cmp == 0) second_index = r;
        }
       //cout << "first index is: " << first_index << "\n";
       //cout << "second index is: " << second_index << "\n";
        if(first_index == -9 && second_index == -9) cout <<"0\n";
        else if(first_index != -9 && second_index != -9) cout << (first_index - second_index + 1)  << "\n";
        //if(first_index == second_index && first_index != -9) cout <<"1\n";
    }





    return 0;
}