#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, it = 0;
vector<string> dictionary;
vector<string> rules;
vector<string> passwords;
string currentRule = "";

void backtrack(string p, int sz) {
  if (it == sz) {
    passwords.push_back(p);
    return;
  } 
  bool word = (currentRule[it] == '#' ? 1 : 0);
  if(word) {
    for(int i = 0; i < n; ++i) {
      ++it;
      backtrack(p + dictionary[i], sz);
      --it;
    } 
  } else {
      
      for(int i = 0; i < 10; ++i) {
        ++it;
        backtrack(p + to_string(i), sz);
        --it;
      }
      
  } 
}




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string word, rule;
  while(cin >> n){
    cout << "--\n";
    for(int i = 0; i < n; ++i){
      cin >> word;
      dictionary.push_back(word);
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
      cin >> rule;
      rules.push_back(rule);
    }
    for(int i = 0; i < m; ++i){
      currentRule = rules[i];
      int sizeCurrentRule=(int) rules[i].size(); 
      backtrack("", sizeCurrentRule);
    }
    //sort(passwords.begin(), passwords.end());
    for (string p: passwords)
      cout << p << "\n";
    dictionary.clear();
    rules.clear();
    passwords.clear();
  }
}