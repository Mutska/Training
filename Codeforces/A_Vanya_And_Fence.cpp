#include <iostream>
using namespace std;
int main(){

  int n,h,m;
  int counter = 0;

  scanf("%d %d",&n,&h);

  while(n>0){
    scanf("%d",&m);
    if(m>h){
      counter+=2;
    }else{
      counter+=1;
      }
   --n;

    
    }
    printf("%d\n",counter);
  


  return 0;
}
