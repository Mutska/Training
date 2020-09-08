#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

bool these(char chr) {
    return !isalpha(chr);
    }

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> dictionary;
    string s = "";
    char c;
    bool begin, end;
    begin = end = false;
    while(cin.get(c)) {
    //if(isblank(c)) cout << "space here\n";
    if(isalpha(c))
        s += tolower(c), begin = true;
    if(begin && !isalpha(c))    
        end = true;
    if(s.size() != 0 && begin && end) 
        dictionary.insert(s), s = "", begin = end = false;
         
    //s.erase(remove_if(s.begin(),s.end(),these), s.end());
    //transform(s.begin(), s.end(), s.begin(), ::tolower);
    //dictionary.insert(s);
    }
   // cout << "Last curren s is: " << s << "\n";
    for(auto it = dictionary.begin() ; it != dictionary.end(); it++)
        cout << *it << "\n";
    return 0;
}