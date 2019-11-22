#include <iostream>
#include <math.h>
#include<string>
using namespace std;


int main(){
long  double n,m,a;
long  long  int y,c;
long long int r = 1;
long  double x,f,t;
string w,z;
 cin>>n;
 cin>>m;
 cin>>a;
 //    clock_t startTime = clock();
  x = 0;
  c = 0;
  y = 0;
  if(n == m && (m ==a || m < a))
    cout<<r<<endl;
  if(n == m && m>a){
    x = ceil(m/a);
    f = x*x;
    z = to_string(f);
    z.erase(z.begin()+z.find('.'),z.end());
    cout<<z<<endl; 
  }
   if(n<m && m>a && n<a){
     while(m>x){
      x+=a;
      c++;
    }
     cout<<c<<endl;
   }
   if(n>m && m<a && n>a){
     while( n >x){
      x+=a;
      c++;
    }
     
     cout<<c<<endl;
   }
   if( (n > m && m>a) || ( m > n && n>a) ){
    x = ceil(m/a);//Uso funcion techo porque la otra manera de implementarlo es la forma  "NAIVE" y da TLE
    t = ceil(n/a);
    f = x*t;
    z = to_string(f);
    z.erase(z.begin()+z.find('.'),z.end());
    cout<<z<<endl;
    
  }
    if( n < m && m< a){
      cout<<r<<endl;

    }
    if(n>m && (m == a || n==a)){
     while(n>x){
      x+=a;
      c++;
    }
     cout<<c<<endl;
    }
    if(m>n && (n == a || m==a)){
     while(m>x){
      x+=a;
      c++;
    }
     cout<<c<<endl;
    }
    //     cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;   


  return 0;
}
