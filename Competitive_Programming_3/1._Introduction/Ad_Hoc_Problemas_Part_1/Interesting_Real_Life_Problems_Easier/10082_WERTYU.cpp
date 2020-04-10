//2020-01-06 WERTYU by Mutska

#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

int main(){

	unordered_map<char, char> mapping;
	mapping['1'] = '`';
	mapping['2'] = '1';
	mapping['3'] = '2';
	mapping['4'] = '3';
	mapping['5'] = '4';
	mapping['6'] = '5';
	mapping['7'] = '6';
	mapping['8'] = '7';
	mapping['9'] = '8';
	mapping['0'] = '9';
	mapping['-'] = '0';
	mapping['='] = '-';
	mapping['W'] = 'Q';
	mapping['E'] = 'W';
	mapping['R'] = 'E';
	mapping['T'] = 'R';
	mapping['Y'] = 'T';
	mapping['U'] = 'Y';
	mapping['I'] = 'U';
	mapping['O'] = 'I';
	mapping['P'] = 'O';
	mapping['['] = 'P';
	mapping[']'] = '[';
	mapping['\\'] =']';
	mapping['S'] = 'A';
	mapping['D'] = 'S';
	mapping['F'] = 'D';
	mapping['G'] = 'F';
	mapping['H'] = 'G';
	mapping['J'] = 'H';
	mapping['K'] = 'J';
	mapping['L'] = 'K';
	mapping[';'] = 'L';
	mapping['\''] = ';';
	mapping['X'] = 'Z';
	mapping['C'] = 'X';
	mapping['V'] = 'C';
	mapping['B'] = 'V';
	mapping['N'] = 'B';
	mapping['M'] = 'N';
	mapping[','] = 'M';
	mapping['.'] = ',';
	mapping['/'] = '.';
	string line;

	while(getline(cin, line)){
		string result = "";
	 	int size = line.size();
		for(int i = 0; i < size; i++){
			if(isspace(line[i])){
				result += " ";
				continue;
			}
			string s(1, mapping[line[i]]);
			result += s ;
		
		}	
		cout << result << "\n";
	
	}




	return 0;
}
