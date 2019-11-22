#include<iostream>
using namespace std;

int main(){
  int n,c = 0;
  string r;
  cin>>n;
  n++;
  while(n){
    getline (cin,r);
    if(r[0]=='+' || r[2] == '+'){
      c++;
    }
    if(r[0]=='-' || r[2] == '-'){
      c--;
    }
    n--;
  }
  cout<<c<<endl;
}
