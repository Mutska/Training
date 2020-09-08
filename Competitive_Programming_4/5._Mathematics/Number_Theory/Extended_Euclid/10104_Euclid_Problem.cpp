#include <iostream>

using namespace std;

long gcd(long a, long b, long & x, long & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long x1, y1;
    long d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main() {
    long A, B, X, Y, D;
    while(cin >> A >> B){
        D = gcd(A, B, X , Y);
        if( A == 0 && B == 0) cout << "1 0 0\n";
        else{ 
        if(A*X + B*Y == D)
            if(A*Y + B*X == D && Y <= X) 
                cout <<  Y << " " << X;
            else
                cout <<  X << " " << Y;
        else
            cout <<  Y << " " << X;
        cout << " "  << D << "\n";
        }
        
    }
}