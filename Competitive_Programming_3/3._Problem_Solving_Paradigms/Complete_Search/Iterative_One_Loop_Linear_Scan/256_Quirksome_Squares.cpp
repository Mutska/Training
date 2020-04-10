#include <iostream>
#include <string>
//#include <sstream>

using namespace std;
/*
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int digits;
    while(cin >> digits) {
        if(digits == 2) cout << "00\n01\n81\n";
        else if(digits == 4) cout << "0000\n0001\n2025\n3025\n9801\n";
        else if(digits == 6) cout << "000000\n000001\n088209\n494209\n998001\n";
        else cout << "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";
    }

      /*
    for(int i = 0; i < 100000000 ; i++) {
        if(i < 10) original = "0000000", original = original +  patch::to_string(i);
        else if(i >= 10 && i < 100) original = "000000", original = original + patch::to_string(i);
        else if(i >= 100 && i < 1000) original = "00000", original = original + patch::to_string(i);
        else if(i >= 1000 && i < 10000) original = "0000", original = original + patch::to_string(i);
        else if(i >= 10000 && i < 100000) original = "000", original = original + patch::to_string(i);
        else if(i >= 100000 && i < 1000000) original = "00", original = original + patch::to_string(i);
        else if(i >= 1000000 && i < 10000000) original = "0", original = original + patch::to_string(i);
        else original = patch::to_string(i);
        x = stoi(original.substr(0,4));
        y = stoi(original.substr(4,4));
        res = (x+y)*(x+y);
        if(res == i) cout << original << "\n";

    }
    */
    return 0;
}