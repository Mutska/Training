#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int iqs[100001];
    int T, N, iq, max_iq, max_difference, index;
    cin >> T;
    while(T--) {
        cin >> N;
        index = 0;
        while(N--)
            cin >> iq, iqs[index++] = iq;
        max_iq = -150001, max_difference = -150001;
        for(int i = 0; i < index - 1; i++) {
            if(iqs[i] > max_iq)
                max_iq = iqs[i];
            if(max_iq - iqs[i + 1] > max_difference)
                max_difference = max_iq - iqs[i + 1];
        }
            cout << max_difference << "\n";
    }
    return 0;
}