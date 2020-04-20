//hackerrank problem
#include <iostream>
#include <cmath>
using namespace std;
bool isPerfectSquare(long double x) 
{   
  long double sr = sqrt(x); 
  
  return ((sr - floor(sr)) == 0); 
} 
  
int main() { 
  long double N;
  int T; 
  cin >> T;
  while(T--) {
      cin >> N;
      if(isPerfectSquare(5*N*N+4) || isPerfectSquare(5*N*N-4))
        cout << "IsFibo\n";
      else
        cout << "IsNotFibo\n";
  }
  
} 