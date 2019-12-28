// 2019-12-17 TEX Quotes by Mutska

#include <iostream>
#include <string>


using namespace std;

int main(){
	
	string buffer_text;
	string original_text = "";
	string new_text = "";
	int count = 1;

	while (getline(cin, buffer_text)) {
		
		original_text += buffer_text;
		original_text += "\n";
	
	}

	for (char c: original_text) {
		if ( (c == '\"')  && ((count % 2)  == 1) ) {	
			new_text += "`";	
			new_text += "`";	
			count++;
		}else if( (c == '\"') && ((count % 2) == 0) ) {
			new_text += "'";
			new_text += "'";
			count++;
		}else{
			new_text += c;
		}
	}
	
	cout << new_text;

	return 0;
}
