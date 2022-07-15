#include <iostream>
#include <iomanip>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double ncows, ncars, nshow;
    while(cin >> ncows >> ncars >> nshow) {
        double PC = ncars/(ncows+ncars);
        double PV = ncows/(ncows+ncars);
        double PGV = ncars/(ncows + ncars - nshow - 1);
        double PGC = (ncars - 1)/(ncows + ncars - nshow - 1);
        cout << fixed << setprecision(5) << PC*PGC + PV*PGV << "\n";
    }
    return 0;
}