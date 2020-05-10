#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cfloat>

using namespace std;

int main() {

    cout << "Maximum value for int: " << numeric_limits<int>::max() << "\n";
    cout << "Maximum value for long int: " << numeric_limits<long int>::max() << "\n";
    cout << "Maximum value for long long int: " << numeric_limits<long long int>::max() << "\n";
    cout << "Maximum value for unsigned long int: " << numeric_limits<unsigned long int>::max() << "\n";
    cout << "Maximum value for unsigned long long int: " << numeric_limits<unsigned long long int>::max() << "\n";
    cout << "Maximum value for float: " << numeric_limits<float>::max() << "\n";
    cout << "Maximum value for double: " << numeric_limits<double>::max() << "\n";
    cout << "Maximum value for long double: " << numeric_limits<long double>::max() << "\n";
    cout << "\n\n";
    long double LOOKME = numeric_limits<long double>::max() ;
    LOOKME  -= 2;
    LOOKME += 2;
    LOOKME /= 2;
    LOOKME *= 2;
    if(fmod(LOOKME , numeric_limits<long double>::max()) == 0)
        cout << "WTF!!!!!\n";
    cout <<setprecision(7) << LOOKME << "\n";
    




}