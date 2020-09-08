#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<pair<int,int>> stream;
    unordered_map<int, int> position;
   string command;
   int task, period, N;

    while(1) {
        cin >> command;
        if(command == "#") break;
        cin >> task >> period;
        position[task] = period;
        stream.push({-period, -task});
    }
    cin >> N;
    while(N--) {
        task = stream.top().second;
        period = position[(-task)] + (-stream.top().first);
        cout << - task << "\n";
        stream.pop();
        stream.push({-period, task});
    } 


}