//2020-01-14 Soundex by Mutska

#include <iostream>
#include <string>
using namespace std;

int main() {
	string mapping[7] = {"","BFPV", "CGJKQSXZ", "DT", "L","MN","R"};
	string result, in;
	size_t flag;
	bool f;
	while(cin >> in){
		result = "";
		char current = '9';
		for(int i = 0  ; i < (int) in.size(); i++) {
			f = false;
			for(int j = 1; j < 7; j++) {
				flag = mapping[j].find_first_of(in[i]);
				if (flag != string::npos){
					if (current != (to_string(j))[0]) {
						result += to_string(j); current = (to_string(j))[0]; f = true ; break;
					}else{
						f = true;
					}
				}
			}
						
			if(!f)
				current = '9';
		}	
		cout << result << "\n";
	}
}
