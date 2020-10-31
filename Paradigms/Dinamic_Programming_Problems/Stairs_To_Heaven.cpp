#include <bits/stdc++.h>
using namespace std;

long long stairwayToHeaven_Recursive(long long n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    return stairwayToHeaven_Recursive(n - 1) + stairwayToHeaven_Recursive(n - 2);
}

long long stairwayToHeaven_Bottom_Up(long long n){
    long long ways3[n+1];
    ways3[0] = 1;
    ways3[1] = 1;
    for(int i = 2; i <= n; i++ ){
        ways3[i] = ways3[i-1] + ways3[i-2];
    }
    return ways3[n];
}

long long ways2[101] = {0};
long long stairwayToHeaven_Top_Down(long long n) {
    if(n == 0) ways2[n] = 1;
    else if(n == 1) ways2[n] = 1;
    else if(ways2[n] != 0) return ways2[n];
    else ways2[n]= stairwayToHeaven_Top_Down(n - 1) + stairwayToHeaven_Top_Down(n-2);
    return ways2[n];
}

int main(){
   //cout << "BOTTOM UP APPROACH\n";
   //cout << "Number of ways to reach heaven with 5 stairs is " << stairwayToHeaven_Bottom_Up(5)  << "\n";
   //cout << "Number of ways to reach heaven with 8 stairs is " << stairwayToHeaven_Bottom_Up(8)  << "\n";
   //cout << "Number of ways to reach heaven with 14 stairs is " << stairwayToHeaven_Bottom_Up(14) << "\n";
   //cout << "TOP DOWN APPROACH\n";
   //cout << "Number of ways to reach heaven with 5 stairs is " << stairwayToHeaven_Top_Down(5)   << "\n";
   //cout << "Number of ways to reach heaven with 8 stairs is " << stairwayToHeaven_Top_Down(8)   << "\n";
   //cout << "Number of ways to reach heaven with 14 stairs is "<< stairwayToHeaven_Top_Down(14)  << "\n";
   //cout << "RECURSIVE APPROACH\n";
   //cout << "Number of ways to reach heaven with 5 stairs is " << stairwayToHeaven_Recursive(5)  << "\n";
   //cout << "Number of ways to reach heaven with 8 stairs is " << stairwayToHeaven_Recursive(8)  << "\n";
   //cout << "Number of ways to reach heaven with 14 stairs is " << stairwayToHeaven_Recursive(14)  << "\n";
   //cout <<  stairwayToHeaven_Recursive(50) << "\n";
   //cout <<  stairwayToHeaven_Top_Down(93) << "\n";
   //cout <<  stairwayToHeaven_Bottom_Up(93) << "\n";


    return 0;
}
