#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, n, bill, min, max;
    long long result;
    while(cin >> n, (n || false)) {
        multiset<int> urn;
        result = 0;
        while(n--) {
            cin >> k;
            while(k--)
                cin >> bill,  urn.insert(bill);
            auto min_it = urn.begin();
            auto max_it = --urn.end();
            min = *min_it;
            max = *max_it;
            result += (max - min);
            urn.erase(min_it);
            urn.erase(max_it);

        }
        cout << result << "\n";

    }

    return 0;
}