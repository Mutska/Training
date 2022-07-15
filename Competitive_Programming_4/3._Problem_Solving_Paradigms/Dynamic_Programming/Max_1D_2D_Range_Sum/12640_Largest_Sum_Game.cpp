#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;

    while(getline(cin, line)) {
        stringstream ss(line);
        int n;
        vector<int>  A;
        while(ss >> n) A.emplace_back(n);

        int sum  = 0, ans = 0;
        for(int &a :A) {
            sum += a;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        cout << ans << "\n";
    }
    return 0;
}