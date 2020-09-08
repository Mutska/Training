//2020-01-15 Army Buddies by Mutska

#include <iostream>
#include <set>
using namespace std;


int main() {

	//ios::sync_with_stdio(0);

	int S, B, L, R;
	set<int> army;
	while(cin >> S >> B, (S || B)) {
		for(int i = 1; i <= S; i++) army.insert(i); // cout << "Inserting: " << i << "\n";}
		while(B--) {
			cin >> L >> R;
			for(int i = L; i <= R; i++) army.erase(i);// cout << "Erasing: " << i << "\n";}
			auto lit = army.lower_bound(L);
			(lit != army.begin()) ? cout << *(--lit) << " " : cout << "* ";
			auto rit = army.lower_bound(R);
			(rit != army.end()) ? cout << *(rit) << "\n" : cout << "*\n";
		}
		army.clear();
		cout << "-\n";
	
	}
	



	return 0;
}
