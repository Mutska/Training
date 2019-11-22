#include<string>
#include<iostream>
using namespace std;

int main(){
  string w;
  int n;
  cin>>n;
  while(n){
    cin>>w;
    if(w.size()>10){
      cout<<w.front();
      cout<<w.size()-2;
      cout<<w.back()<<endl;
    }else{
      cout<<w<<endl;
    }
    n--;
  }
  return 0;
}
