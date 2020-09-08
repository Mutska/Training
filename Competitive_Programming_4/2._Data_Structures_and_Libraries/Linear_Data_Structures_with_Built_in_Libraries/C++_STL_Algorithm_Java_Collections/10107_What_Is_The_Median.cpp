// 2020-01-23 What is the Median? by Mutska
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    vector<long long> series;
    long long x;

    while(cin >> x) {
        series.push_back(x);
        if(series.size() == 1) {cout << x << "\n"; continue;}
        int middle = series.size() / 2;
        nth_element(series.begin(), series.begin() + middle, series.end());   
        if (series.size() % 2 == 0) {
            nth_element(series.begin(), series.begin() + middle - 1, series.end());
            cout << (series[middle - 1] + series[middle]) / 2 << "\n";   
        } else
            cout << series[middle] << "\n";
    }



    return 0;
}
