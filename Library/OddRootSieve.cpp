#include "Template.h"


int main() {

    int n = 1000;

    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 3; i*i <= n; i += 2){
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j+= i) 
                is_prime[j] = false;
        }
    }
    cout << 2 << " ";
    for(int i = 3; i <= n; i += 2)  
        if(is_prime[i])
            cout << i << " ";
    
    cout << "\n";

}