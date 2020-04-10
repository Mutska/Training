#include <iostream>
#include <map>
#include <string>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    string line, key, value;
    map<string, string> dictionary;

    while(1) {
        getline(cin, line);
        size_t pos = line.find_last_of(' ');
        value = line.substr(0, pos);
        key = line.substr(pos + 1);
        dictionary[key] = value;
        if(line.size() == 0) break;

    }
    while(cin >> key) {
        if(dictionary[key].size() == 0)
            cout << "eh" << "\n";
        else
            cout << dictionary[key] << "\n"; 
    }

    return 0;
}