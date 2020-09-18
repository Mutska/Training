#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, maximum, count;
    while(cin>>n,  (n || 0)) {
        map <vector<int>, int> frosh;
        vector <int> combination(5);
        maximum = 0;
        while(n--) {
            for(int i = 0; i < 5; ++i) cin >> combination[i];
            sort(combination.begin(), combination.end());
            frosh[combination]++;
		}
		for (auto it = frosh.begin(); it != frosh.end(); ++it)
			if(it->second > maximum) maximum = it->second;
        count = 0;
		for (auto it = frosh.begin(); it != frosh.end(); ++it)
			if(it->second == maximum) ++count;
        cout << maximum*count << "\n";
	}
	return 0;
}