#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a(5);
int it = 1;
int ans = 0; 
bool possible= false; 
void backtrack(int ans){

  if(possible) return; 
  if(ans == 23 && it==5){
    possible=true;
    return; 
  }
  if (it == 5){
    return; 
  } 

  ans += a[it]; 
  it++; 
  backtrack(ans);
  it--; 
  ans -= a[it]; 

  ans -= a[it];
  it++; 
  backtrack(ans);
  it--;
  ans += a[it]; 

  ans*= a[it]; 
  it++; 
  backtrack(ans); 
  it--; 
  ans = (int) (ans / a[it]); 

}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]) {
    possible = false;
    if(!(a[0] && a[1] && a[2] && a[3] && a[4])) break;
    sort(a.begin(), a.end());
    do {
        ans = a[0];
        backtrack(ans);
        if(possible) break;
    } while(next_permutation(a.begin(), a.begin() + 5));
    
    if(possible) cout<<"Possible\n"; 
    else cout<<"Impossible\n"; 
  }
} 