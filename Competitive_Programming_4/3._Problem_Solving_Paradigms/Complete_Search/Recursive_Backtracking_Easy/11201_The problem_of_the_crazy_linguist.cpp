#include <iostream>
#include <string>

using namespace std;
double c[150]; 
int r[150], n;
double sum = 0.0;
int noWords = 0;


string vocales="aeiou"; 
string consonantes="bcdfghjklmnpqrstvwxyz";

bool can(char x){
  return (r[x]>=0 && r[x]<3); 
}

double SBC(string w){
  double val = 0;
  for(int i=0; i < (int) w.size(); ++i){
    val += ((double)(i+1))*c[w[i]];
  }
  return val;
}

void backtrack(int it, string s){
  if(n == it){
    noWords++; 
    sum += SBC(s);
    return; 
  }
  if(it%2==1){
    for(char l: vocales){
      if(can(l)){
        r[l]++; 
        backtrack(it+1, s+l); 
        r[l]--;
      }
    }
  }
  else{
    for(char l : consonantes){
      if(can(l)){
        r[l]++;
        backtrack(it+1, s+l);
        r[l]--;
      }
    }
  }
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
c['a'] = 12.53;
c['b'] = 1.42;
c['c'] = 4.68;
c['d'] = 5.86;
c['e'] = 13.68;
c['f'] = 0.69;
c['g'] = 1.01;
c['h'] = 0.70;
c['i'] = 6.25;
c['j'] = 0.44;
c['k'] = 0.00;
c['l'] = 4.97;
c['m'] = 3.15;
c['n'] = 6.71;
c['o'] = 8.68;
c['p'] = 2.51;
c['q'] = 0.88;
c['r'] = 6.87;
c['s'] = 7.98;
c['t'] = 4.63;
c['u'] = 3.93;
c['v'] = 0.90;
c['w'] = 0.02;
c['x'] = 0.22;
c['y'] = 0.90;
c['z'] = 0.52;
r['a'] = 0;
r['b'] = 0;
r['c'] = 0;
r['d'] = 0;
r['e'] = 0;
r['f'] = 0;
r['g'] = 0;
r['h'] = 0;
r['i'] = 0;
r['j'] = 0;
r['k'] = 0;
r['l'] = 0;
r['m'] = 0;
r['n'] = 0;
r['o'] = 0;
r['p'] = 0;
r['q'] = 0;
r['r'] = 0;
r['s'] = 0;
r['t'] = 0;
r['u'] = 0;
r['v'] = 0;
r['w'] = 0;
r['x'] = 0;
r['y'] = 0;
r['z'] = 0;  
  int t; 
  string w; 
  cin>>t; 
  while(t--){
    sum=0.0; 
    noWords=0; 
    cin>>w; 
    n =  w.length();
    string s = "";
    backtrack(1,s + w[0]);
  


    if(SBC(w) < (sum/(double) noWords)){
      cout<<"below\n";
    } 
    else{
      cout<<"above or equal\n"; 
    }

  }
  return 0; 
}