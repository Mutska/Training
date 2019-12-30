//2019-12-30 Optimal Parking by Mutska

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){


	int t, n, shop, temp;
	vector<int> shops;

	cin >> t;

	while(t--){
		cin >> n;
		temp = n;
		while(n--){
			cin >> shop;
			shops.push_back(shop);
		
		}
		sort(shops.begin(), shops.end());
		cout << (shops[temp-1] - shops[0])*2 << "\n";
		shops.clear();
		
	
	}



}






