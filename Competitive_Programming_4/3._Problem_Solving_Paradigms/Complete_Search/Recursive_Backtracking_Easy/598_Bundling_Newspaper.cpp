#include <bits/stdc++.h>


using namespace std; 


vector<string> newspapers; 
int n, a, b;

void backtrack(string st, int flag,  int tam, int tot){
    if(tam == tot){
      cout<<st<<"\n"; 
    }
    else{
      for(int i = flag; i < (int)newspapers.size(); ++i){
        if(tam==0){
          backtrack(newspapers[i], i+1, tam+1 ,  tot);
        }
        else{
          backtrack( st+", "+newspapers[i], i + 1, tam+1, tot); 

        }
      }
    }
}





int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; 
  string s, token, aa, bb ,newspaper; 
  cin>>t;
  cin.ignore();
  cin.ignore();
  while(t--){ 
    newspapers.clear(); 
    n=0; 
    a=0; 
    b=0; 
    getline(cin, s);

    while(getline(cin, newspaper)) {
      if (newspaper.empty()) break;
      newspapers.emplace_back(newspaper);
    }

    stringstream ss(s);
    int count = 0;
    while (ss >> token) {
      if (count == 0) aa = token;
      if (count == 1) bb = token;
      ++count;
    }
    if (count == 1) {
      if (aa[0] == '*') {
        for(int i=1; i<= newspapers.size(); ++i){
          cout<<"Size "<<i<<"\n"; 
          backtrack("", 0, 0, i); 
          cout<<"\n"; 
        }

      } else{
        n = stoi(aa);
        cout<<"Size "<<n <<"\n"; 
        backtrack("", 0, 0, n); 
        cout<<"\n"; 
      }
    } else {
      a = stoi(aa);
      b = stoi(bb);
      for(int i=a; i <= b ; ++i){
          cout<<"Size "<<i<<"\n"; 
          backtrack("", 0, 0, i); 
          cout<<"\n"; 
      }
    }
    if (t) cout << "\n";
  }
}