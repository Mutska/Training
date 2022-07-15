#include <iostream>
#include <vector>
using namespace std;

int N, L;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int numWord=0; 

bool can(string line){

  int n = line.size();
  int mit = n/2; 
  bool bd=false; 
  //cout<<n<<" "<<mit<<" "<<bd<<"\n"; 
  for(int i=1; i<=mit; ++i){
    bd=false; 
    for(int j=0; j<i; ++j){
      if(line[n-1-j] != line[n-1-j-i]){
        bd=true; 
        break; 
      }
    }
    if(!bd) return false; 
  }

  return true; 
}

bool backtrack(string word) {

  if(!can(word)) return false; 

  if( numWord == N){
    for(int i=0; i < (int) word.size(); ++i){
      if(i && i%4==0){
        if(i%64 == 0 ) cout<<"\n"; 
        else cout<<" "; 
      }
      cout<<word[i]; 
  }
  cout<< "\n" << word.size()<<"\n";
  return true;   
  }

  ++numWord; 

  for(int i = 0; i < L; ++i) {
    if(backtrack(word+alphabet[i])) return true; 
  }

  return false; 
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin >> N >> L, (N || L)) {
    numWord = 0;
    backtrack("");
  }

}