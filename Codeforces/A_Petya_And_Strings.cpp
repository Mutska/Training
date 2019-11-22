#include<iostream>
#include<algorithm>
//#include<cstring>
using namespace std;

int main(){
  string a,b;
  bool c;
  //char x[101];
  //  char y[101];
  //  memset(x,'a',sizeof(x));
  //  memset(y,'a',sizeof(y));
  cin>>a;
  cin>>b;
  std::transform(a.begin(),a.end(),a.begin(),::tolower);
  std::transform(b.begin(),b.end(),b.begin(),::tolower);
  /*  for(int i = 0;i<a.size();i++){
    x[i] = a[i];
  }
  for(int i = 0;i<b.size();i++){
    y[i] = b[i];
  }
  c = lexicographical_compare(x,x+a.size(),y,y+b.size());
  */
  if(a.compare(b) == 0){
    cout<<"0"<<endl;
  }else if(a.compare(b)<0){
    cout<<"-1"<<endl;
  }else if(a.compare(b)>0){
    cout<<"1"<<endl;
  }

  return 0;
}
