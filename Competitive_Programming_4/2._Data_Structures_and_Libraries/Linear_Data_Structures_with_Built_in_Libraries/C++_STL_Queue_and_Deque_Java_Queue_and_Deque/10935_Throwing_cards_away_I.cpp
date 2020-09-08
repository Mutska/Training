#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, j, discarded, mov;
    while(cin >> n, (n || 0)) {
        queue<int> deck;
        for(int i = 1; i <=n; i++)
            deck.push(i);
        cout << "Discarded cards:";
        j = 1;
        while(deck.size() >= 2) {
            if(j++ < 2) cout << " ";
            discarded = deck.front();
            deck.pop();
            mov = deck.front();
            deck.pop();
            deck.push(mov);
            cout << discarded;
            if(!(deck.size() < 2))
                cout << ", ";
        }
        cout << "\nRemaining card: " << deck.front() << "\n";

    }



    return 0;
}