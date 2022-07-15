#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

string t, p, backup;
int n, m;
vector<int> indices;

bool good(int d) {


	for(int  i = 0; i < d; ++i) t[indices[i]] = '$';


	int j = 0;

	for(int i = 0; i < n; ++i) {
		if(t[i] == p[j]) ++j;
		if (j == m) break;
	}

	for(int  i = 0; i < d; ++i) t[indices[i]] = backup[indices[i]];

	return j == m;
}


int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	string numbers;
	int number;
	cin >> t >> p;
	n = t.size();
	m = p.size();

	backup = t;
	cin.get();

	getline(cin, numbers);
	stringstream ss(numbers);

	while(ss >> number) indices.emplace_back(--number);
	


	int l = 0;
	int r = n;

	 while(r > l + 1) {
	 	int m = (l + r) / 2;
	 	if (good(m)) l = m;
	 	else r = m;
	 }

	 cout << l << "\n";

	return 0;
}





