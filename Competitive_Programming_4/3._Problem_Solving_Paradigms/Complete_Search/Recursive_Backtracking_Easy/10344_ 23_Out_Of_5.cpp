#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a(5);
int it = 1;
int ans = 0; 
bool possible= false; 
string s = ""; 

int operate(int i, int j) {
  if (s[j] == '+') ans += a[i];
  else if (s[j] == '-') ans -= a[i];
  else if (s[j] == '*') ans *= a[i];
}

void backtrack(){
  if (possible) return;
  if (it == 5){
    operate(1, 0);
    operate(2, 1);
    operate(3, 2);
    operate(4, 3);
    if (ans == 23) {
      possible = true;
    }
    ans = a[0];
    return; 
  } 

  ++it;
  s+="+"; 
  backtrack();
  s.pop_back(); 
  --it;

  ++it;
  s+="-";  
  backtrack();
  s.pop_back();  
  --it;

  ++it;
  s+="*"; 
  backtrack(); 
  s.pop_back(); 
  --it;

}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]) {
    if(!(a[0] && a[1] && a[2] && a[3] && a[4])) break;
    possible = false;
    int sum = 0;
    for (int i = 0; i < 5; ++i) sum += a[i];
    int mult = 1;
    for (int i = 0; i < 5; ++i) mult *= a[i];
    if (sum < 23 && mult < 23) {
      cout << "Impossible\n";
      continue;
    }
    sort(a.begin(), a.end());
    do {
        ans = a[0];
        backtrack();
        if(possible) break;
    } while(next_permutation(a.begin(), a.begin() + 5));
    
    if(possible) cout<<"Possible\n"; 
    else cout<<"Impossible\n"; 
  }
  return 0;
} 