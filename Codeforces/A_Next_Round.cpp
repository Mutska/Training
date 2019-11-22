#include<iostream>
#include<string.h>
using namespace std;

int main(){
  int n,k,r;
  int p[51];
  int c = 0;
  memset(&p,-1,sizeof(p));
  scanf("%d %d",&n,&k);
  for(int i = 1;i<=n;i++){
     cin>>p[i];
  }
  int  x = 1;
  int y = n;
  while(y>0){
    if(p[x] >= p[k] && ( p[x]>0))
      c++;
    x++;
    y--;
		       
  }
   cout<<c<<endl;


  return 0;
}
