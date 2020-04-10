#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    string job, line;
    int necessary, salary;
    map<string,int> jobs;
    while(m--) {
       cin >> job >> necessary; 
       jobs[job] = necessary;
    }
    while(n--) {
        salary = 0;
        while(1) {
            getline(cin, line);
            if(line == ".") break;
            stringstream iss(line);
            while(iss >> job) {
                salary += jobs[job];
            }
        }
        cout << fixed <<  salary << "\n";
    }


    return 0;
}