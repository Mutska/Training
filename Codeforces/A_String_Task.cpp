#include<iostream>
using namespace std;

int main(){
  string w;
  string r;

  cin>>w;
  for(int i = 0;i<w.length();i++){
    if(w[i] == 'A' || w[i] == 'E' || w[i] == 'I' || w[i] == 'O' || w[i] == 'U' || w[i] == 'Y' )continue;
    if(w[i] == 'a' || w[i] == 'e' || w[i] == 'i' || w[i] == 'o' || w[i] == 'u' || w[i] == 'y' )continue;
      r+='.';
      r+=tolower(w[i]);   
      
  }
  cout<<r<<endl;
  

  return 0;
}
