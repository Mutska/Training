#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
	while (getline(cin, line)) {
		list<char> res;
		auto it = res.begin();

		for (int i = 0; i < (int) line.size(); i++) {
			if (line[i] == '[')
				it = res.begin();
			else if (line[i] == ']')
				it = res.end();
			else
				res.insert(it, line[i]);
		}
        for(auto c: res) cout << c;
        cout <<"\n";
	}

	return 0;
}