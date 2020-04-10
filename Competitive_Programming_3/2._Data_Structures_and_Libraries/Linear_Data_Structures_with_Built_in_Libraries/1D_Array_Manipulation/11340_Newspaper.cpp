//2020-01-14 Newspaper by Mutska
#include <unordered_map>
#include <iostream>
#include <string> 
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	unordered_map<char, int> table;
	char m;
	string line;
	double  result;
	int N, K, M, value;
	cin >> N;
	while(N--){
		result = 0;
		table.clear();
		cin >> K;
		while(K--){
			cin >> m >> value;
			table[m] = value;	
		}
		cin >> M;
		cin.ignore();
		while(M--){
			getline(cin, line);
			for(int i = 0; i < (int) line.size(); i++)
				if(table.count(line[i]) > 0) result += table[line[i]];
		}
		cout << fixed << setprecision(2) << result / 100 << "$" << "\n";
	}
    return 0;
}
