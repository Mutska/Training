#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
  string a;
  string r;
  char s[101];
  memset(s,'a',sizeof(s));
  //  cout<<stoi(a);
  cin>>a;
  for(int i = 0;i<a.size();i+=2){
    s[i] = a[i];
  }
  sort(s,s+a.size());
  for(int i = 0;i<a.size()/2+1;i++){
      r+=s[i];
      if(i!=a.size()/2)
	r+='+';
    

  }
  cout<<r<<endl;


return 0;
}

