#include <iostream>
#include <bitset>
using namespace std;
bool tricking(bitset<32> &bits) {
    int j = 7;
    for(int i = 31; i > 23; i--) {
        bool temp;
        temp = bits[i];
        bits[i] = bits[j];
        bits[j] = temp;
        j--;
    }
    j = 15;
    for(int i = 23; i > 15; i--) {
        bool temp;
        temp = bits[i];
        bits[i] = bits[j];
        bits[j] = temp;
        j--;
    }
    if(bits[31]) {bits.flip(); return true;}
    return false;

}
int main() {
    int N;
    bitset<32> bits;
    while(cin >> N) {
        bits = N;
        bool res = tricking(bits);
        if(res) {
            cout << N << " converts to ";
            cout << "-" << bits.to_ullong() + 1 << "\n";
        } else {
            cout << N << " converts to ";
            cout << bits.to_ullong() << "\n";
        }
    }
    return 0;
}