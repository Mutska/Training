#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int F, R, f, r;
    while(cin >> F, (F || 0)) {
        cin >>  R;
        vector<double> front;
        vector<double> rear;
        vector<double> ratios;
        while(F--)
            cin >> f, front.emplace_back(f);
        while(R--)
            cin >> r, rear.emplace_back(r);
        for(int i = 0; i < (int) front.size(); i++)  { 
            for(int j = 0; j < (int) rear.size(); j++) {
                double res = front[i] / rear[j];
                ratios.emplace_back(res);
            }
        }
        sort(ratios.begin(), ratios.end());
        //for(double r: ratios)
          //  cout << r << " ";
        //cout << "\n";
        double maximum = 0;
        for(int i = 0; i < ((int) ratios.size()) - 1 ; i++) {
            for(int j = i + 1; j < (int) ratios.size(); j++) {
                double res = ratios[j] / ratios[i];
                //cout << "res is: " << res << "\n";
                maximum = max(maximum, ratios[j] / ratios[i]);
                break;
            }
        }
        cout << setprecision(2) << fixed << showpoint <<  maximum << "\n";
    } 
    return 0;
}