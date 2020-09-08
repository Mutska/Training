//2020-01-15 487-3279 by Mutska

#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
#include <set> 
using namespace std;


int main() {

 ios::sync_with_stdio(0);
 char table[95];

 table['A'] = '2';
 table['B'] = '2';
 table['C'] = '2';
 table['D'] = '3';
 table['E'] = '3';
 table['F'] = '3';
 table['G'] = '4';
 table['H'] = '4';
 table['I'] = '4';
 table['J'] = '5';
 table['K'] = '5';
 table['L'] = '5';
 table['M'] = '6';
 table['N'] = '6';
 table['O'] = '6';
 table['P'] = '7';
 table['R'] = '7';
 table['S'] = '7';
 table['T'] = '8';
 table['U'] = '8';
 table['V'] = '8';
 table['W'] = '9';
 table['X'] = '9';
 table['Y'] = '9';
	int N, D;
	string phone, temp;
	bool flag;
	vector<string> standard;
	set<string> list;
	int counter = 1;
	cin >> D;
	while(D--){
		cin >> N;
		flag = false;
		standard.clear();
		list.clear();
		if(counter++ > 1) cout << "\n";
		while(N--){
			cin >> phone;
			temp = "";
			for(int i = 0; i < (int) phone.size(); i++){
				if(isdigit(phone[i])) {temp += phone[i]; continue;}
				if(isalpha(phone[i]))
					if(phone[i] != 'Q' && phone[i] != 'Z')
						temp += table[phone[i]];
			}
			standard.emplace_back(temp);
			list.emplace(temp);
		}
			sort(standard.begin(), standard.end());
			for(auto x: list){
				int times =  count(standard.begin(), standard.end(), x);
				if(times > 1){
					cout << x.substr(0,3) << "-" << x.substr(3, 4) << " " << times << "\n";
					flag = true;
				}
			}
	   		if(!flag)
	   			cout << "No duplicates.\n";	   	
		
	}	
	return 0;
}
