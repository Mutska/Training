#include <iostream>
#include <vector>


using namespace std;


long long Cat(int n){
    int K = n;
    int N = 2*n;
    long long C = 1;
    for(int i = 0; i < K;++i){
        C *= (N - i);
        C /= (1 + i);
    }
    long long Cat = C / ((long long ) n + 1);
    return Cat;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    vector<long long> cat_numbers;
    for(int i = 1; i <= 20; ++i) cat_numbers.push_back(Cat(i));
    while(cin >> n ){
        for(int i = 0; i < 20; ++i){
            if(n == cat_numbers[i]) cout << i + 1 << "\n";
        }
    }



    return 0;
}