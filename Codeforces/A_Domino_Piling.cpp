#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int N,M;
  double r;
  scanf("%d %d",&N,&M);
  if((N*M)%2 == 0 ){
    cout<<((N*M)/2)<<endl;
  }
  if((N*M)%2 != 0){
    r=floor((N*M)/2);
    cout<<r<<endl;
  }

  return 0;
}
