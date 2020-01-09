//2020-01-07 Anagram by Mutska
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> table;

bool final_rule(char i, char j){
	return table[i] < table[j];
}
 
bool rule(string i, string j){
		return lexicographical_compare(i.begin(),i.end(), j.begin(), j.end(), final_rule);
}
 
int main(){
	
	table['A'] = 0; 
	table['a'] = 1; 
	table['B'] = 2; 
	table['b'] = 3; 
	table['C'] = 4; 
	table['c'] = 5; 
	table['D'] = 6; 
	table['d'] = 7; 
	table['E'] = 8; 
	table['e'] = 9; 
	table['F'] = 10; 
	table['f'] = 11; 
	table['G'] = 12; 
	table['g'] = 13; 
	table['H'] = 14; 
	table['h'] = 15; 
	table['I'] = 16; 
	table['i'] = 17; 
	table['J'] = 18; 
	table['j'] = 19; 
	table['K'] = 20; 
	table['k'] = 21; 
	table['L'] = 22; 
	table['l'] = 23;
	table['M'] = 24;
	table['m'] = 25;
	table['N'] = 26; 
	table['n'] = 27; 
	table['O'] = 28; 
	table['o'] = 29; 
	table['P'] = 30; 
	table['p'] = 31; 
	table['Q'] = 32; 
	table['q'] = 33; 
	table['R'] = 34; 
	table['r'] = 35; 
	table['S'] = 36; 
	table['s'] = 37; 
	table['T'] = 38; 
	table['t'] = 39; 
	table['U'] = 40; 
	table['u'] = 41; 
	table['V'] = 42; 
	table['v'] = 43; 
	table['W'] = 44; 
	table['w'] = 45; 
	table['X'] = 46; 
	table['x'] = 47; 
	table['Y'] = 48; 
	table['y'] = 49;
	table['Z'] = 50;
	table['z'] = 51;
	int T;
	string input;	
	vector<string> sorted;
	cin >> T;
	while(T--){
		cin >> input;
		sort(input.begin(), input.end());
		sorted.clear();
		do{
			sorted.push_back(input);
		}while(next_permutation(input.begin(), input.end()));
	
		sort(sorted.begin(), sorted.end(), rule);
	
		for(auto s :sorted)
			cout << s << "\n";

	}
	return 0;
}
