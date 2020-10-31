#include <iostream>
#include <vector>


using namespace std;

void reflect(vector<string> &A) {
    int N = A.size();
    for(int i = 0; i < N / 2; ++i) swap(A[i], A[N - 1 - i]);
}

void rotate(vector<string> &a) { 
    int N = a.size();
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
            char temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    } 
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, p = 0;
    string a, b;
    while(cin >> N){
        vector<string> A;
        vector<string> B;
        vector<string> C;
        if(N == 1) {
            cin >> a;
            cin >> b;
            if(a == b) cout << "Pattern " << ++p << " was preserved.\n";
            else cout << "Pattern " << ++p << " was improperly transformed.\n";
            continue;
        }
        while(N--) {
            cin >> a;
            cin >> b;
            A.emplace_back(a);
            B.emplace_back(b);
            C.emplace_back(a);
        }
        if(A == B) {
            cout << "Pattern " << ++p << " was preserved.\n";
            continue;
        }
        while(1) {
            rotate(A);
            if(A == B) {
                cout << "Pattern " << ++p << " was rotated 90 degrees.\n";
                break;
            }
            rotate(A);
            if(A == B) {
                cout << "Pattern " << ++p << " was rotated 180 degrees.\n";
                break;
            }
            rotate(A);
            if(A == B) {
                cout << "Pattern " << ++p << " was rotated 270 degrees.\n";
                break;
            }
            reflect(C);
            if(C == B) {
                cout << "Pattern " << ++p << " was reflected vertically.\n";
                break;
            }
            rotate(C);
            if(C == B) {
                cout << "Pattern " << ++p << " was reflected vertically and rotated 90 degrees.\n";
                break;
            }
            rotate(C);
            if(C == B) {
                cout << "Pattern " << ++p << " was reflected vertically and rotated 180 degrees.\n";
                break;
            }
            rotate(C);
            if(C == B) {
                cout << "Pattern " << ++p << " was reflected vertically and rotated 270 degrees.\n";
                break;
            }
            cout << "Pattern " << ++p << " was improperly transformed.\n";
            break; 
        }
    }


    return 0;
}