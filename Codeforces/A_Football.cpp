#include<iostream>
#include<string>

using namespace std;

int main()
{
  string s;
  string zero = "0000000";
  string one = "1111111";
  cin>>s;
  size_t fzero = s.find(zero);
  size_t fone = s.find(one);
  if((fzero != string::npos) || (fone != string::npos)){
    cout<<"YES"<<endl;

  }else{
    cout<<"NO"<<endl;
  }

  return 0;
}
