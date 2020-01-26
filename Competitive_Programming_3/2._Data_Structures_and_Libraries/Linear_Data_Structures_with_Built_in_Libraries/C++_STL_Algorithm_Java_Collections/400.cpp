#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main () {
    
    int N;
    string word;
    vector<string> words;

    while(cin >> N) {
        words.clear();
        while(N--){
            cin >> word;
            words.emplace_back(word);
        }
        sort(words.begin(), words.end());
        int max_size = 0;
        int size = words.size();
        for(auto w: words)
            if(w.size() > max_size) max_size = w.size();
        int max_columns = (60 - max_size) / (max_size + 2);
        double max_space = ceil ((double) size / (double) (max_columns + 1));
        for(int i = 0; i < 60; i++)
            cout << "-";
        cout << "\n";
        int c;
        for (int i = 0; i < max_space; i++) {
                int word_size = words[i].size();
                int space_size = max_size - word_size;
                cout << words[i];
                c = max_space;
                for(int k = 0; k < space_size; k++) cout << " ";
            for (int j = 0 ; j < max_columns; j++) {
                if (i + c < words.size()  ) {
                    cout << "  ";
                }else{
                    continue;
                }
                cout << words[i + c ];
                word_size = words[i+c].size();
                space_size = max_size - word_size;
                for(int k = 0; k < space_size; k++) cout << " ";
                
                c += max_space; 
           }
           cout << "\n";
            
        }

    }


}