#include <iostream>
using namespace std;
int main(){

  int n = 0;
  int c1 = 0;
  int c2 = 0;
  char  c;
  //NO FUNCIONA SI DEJO EL VALOR ORIGINAL INTRODUCIDO  
  scanf("%d",&n);
  
  while(n){
    scanf("%c",&c);
    

    if(c=='A'){

      c1++;

    }else if(c=='D'){
      c2++;

    }

   
    n--;
    

  }

  if(c1>c2){
    printf("Anton\n");

  }else if (c2>c1){

    printf("Danik\n");

  }else if(c1==c2){
    
    printf("Friendship\n");

  }

  return 0;
}
