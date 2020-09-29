#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, l, r, i, j;
    while(cin >> N) {
    vector<int> books(N);
    for(int i = 0; i < N; ++i) cin >> books[i];
    cin >> M;
    sort(books.begin(), books.end());
    l = 0;
    r = N - 1;

    while(r > l) {
        if((books[l] + books[r]) < M) ++l;
        else if((books[l] + books[r]) == M) i = l, j = r, ++l,--r;
        else --r;
    }
    cout << "Peter should buy books whose prices are " << books[i] << " and " << books[j] << ".\n\n";
    }


    return 0;
}