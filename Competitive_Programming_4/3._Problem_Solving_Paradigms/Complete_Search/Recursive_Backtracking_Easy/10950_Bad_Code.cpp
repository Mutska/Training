#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>

using namespace std;

map <string, string>  flc; 

vector<string> answer; 
string codigo; 


void backtrack(string s, int  flag){
  if( flag == codigo.size()) answer.emplace_back(s);
  int it=0; 
  for(int i=flag; i < (int) codigo.size(); ++i){
    it++; 
    if(codigo[flag]=='0'){
      string aux = codigo.substr(flag+1, it); 
      if(flc.count(aux)) backtrack(s+flc[aux], i+2); 
    }
    string  aux = codigo.substr(flag,it); 
    if(flc.count(aux))backtrack(s+flc[aux], i+1); 
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string letter, key;
  int it=0; 
  
  while(cin >> n, n) {
    it++; 
    cout<<"Case #"<<it<<"\n"; 
    flc.clear();
    answer.clear(); 
    while(n--){
      cin >> letter >> key;
      flc[key] = letter;
    }
    cin >> codigo;
    backtrack("", 0);
    sort(answer.begin(), answer.end());
    for(int i = 0; i < (int) answer.size(); ++i) {
      if (i > 99) break;
      cout << answer[i] << "\n";
    }
    cout << "\n";
  }
}