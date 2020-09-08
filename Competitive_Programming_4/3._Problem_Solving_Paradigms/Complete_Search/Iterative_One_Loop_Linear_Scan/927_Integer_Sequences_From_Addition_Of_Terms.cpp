#include <iostream>
#include <vector>

using namespace std;
vector<long long> l;
long long pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long polynomio(long long n) {
    long long pol  = l[0] +  l[1]*pow(n,1)  + l[2]*pow(n,2) + 
                         l[3]*pow(n,3) + l[4]*pow(n,4) + l[5]*pow(n,5) + 
                         l[6]*pow(n,6) + l[7]*pow(n,7) + l[8]*pow(n,8) + 
                         l[9]*pow(n,9) + l[10]*pow(n,10) + l[11]*pow(n,11) + 
                         l[12]*pow(n,12) + l[13]*pow(n,13) + l[14]*pow(n,14) + 
                         l[15]*pow(n,15) + l[16]*pow(n,16) + l[17]*pow(n,17) + 
                         l[18]*pow(n,18) + l[19]*pow(n,19) + l[20]*pow(n,20);
    return pol;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, coefficient, sum, previous;
    int C, grade, d, k, index;
    cin >> C;
    while(C--) {
        l.assign(21,0);
        index = 0;
        cin >> grade;
        grade++;
        while(grade--) {
            cin >> coefficient;
            l[index] = coefficient;
            index++;
        } 
        cin >> d;
        cin >> k;
        n = 1LL;
        previous = n*d;
        sum = n*d;
        bool flag = false;
        for(int i = n*d; i < k; i += n*d) {
           flag = true;
           if(k < i) {
               cout << polynomio(n) << "\n";
               break;
           }
            n++;
            sum += n*d;
            if(sum >= k) { 
                cout << polynomio(n) << "\n";
            }
        }
        if(!flag) cout << polynomio(n) << "\n";

    }
    return 0;
}