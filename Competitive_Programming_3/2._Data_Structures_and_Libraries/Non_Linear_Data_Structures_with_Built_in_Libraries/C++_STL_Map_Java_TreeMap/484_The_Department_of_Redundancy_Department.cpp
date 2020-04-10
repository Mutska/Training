#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> frequency;
    vector<int> numbers;
    int n;
    while(cin >> n) {
        frequency[n]++;
        if(frequency[n]  < 2)
            numbers.push_back(n);
    }  
    for(auto n: numbers)
        cout << n << " " << frequency[n] << "\n";
    return 0;
}