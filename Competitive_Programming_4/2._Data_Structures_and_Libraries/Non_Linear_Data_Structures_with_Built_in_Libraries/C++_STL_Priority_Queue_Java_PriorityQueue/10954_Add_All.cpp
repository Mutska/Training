#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num, cost, calc;
    while(cin >> n, (n || 0)) {
        priority_queue<int> numbers;
        cost = 0;
        while(n--) {
            cin >> num;
            numbers.push(-num);
        }
        while(!numbers.empty() && numbers.size() > 1){
            int left = -numbers.top();
            numbers.pop();
            int right = -numbers.top();
            numbers.pop(); 
            calc = left + right;
            cost += calc;
            numbers.push(-calc);
        }
        cout << cost << "\n" ;
            
    }

    return 0;
}