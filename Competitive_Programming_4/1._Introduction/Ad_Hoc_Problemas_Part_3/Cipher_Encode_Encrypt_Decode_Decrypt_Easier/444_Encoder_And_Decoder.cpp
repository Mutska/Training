#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(getline(cin, s)) {
		char c = s[0];
		int n = s.size();
		if (isalpha(c) || ispunct(c) || c == '?') {
			string r = "";
			for(int i = n-1; i >= 0; --i) {
				int code = (int) s[i];
				string scode = to_string(code);
				reverse(scode.begin(), scode.end());
				r += scode;
			}
			cout << r << "\n";
		} else {
			string r = "";
			int i  = n - 1;
			while(i > 0) {
				string scode = "", test = "";
				scode += s[i];
				scode += s[i-1];
				test  += s[i-1];
				test  += s[i];
				if (test ==  "01" || test == "11" || test == "21") scode += s[i-2], i -= 3;
				else i -= 2;
				int code = stoi(scode);
				char c = (char) code;
				r += c;
			}
			cout << r << "\n";
		}
	}

	return 0;
}
