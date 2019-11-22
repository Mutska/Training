#include <iostream>

int main(){
  int n,A,B,C;
  int counter = 0;
  scanf("%d",&n);
    while(n>0){
      scanf("%d %d %d",&A,&B,&C);

      if(( A == 1 && B == 1) || (A == 1 && C == 1) || (B == 1 && C == 1)){
	counter++;
      }
      n--;      


    }

  printf("%d\n",counter);
  



  return 0;
}
