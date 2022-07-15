#include <iostream>
#include <vector>


using namespace std;


string T, P;
int n, m;
vector<int> b;


void NaiveMatching() {
	for(int i = 0; i <= n - m; ++i) {
		bool found = true;
		for(int j = 0; j < m && found; ++j)
			if(i + j >= n || P[j] != T[i+j]) found = false;
		if (found) cout << "P is found at index " << i << " in T\n";
	}
}

void KmpPreprocess() {
	b.assign(m + 1, 0);
	int i = 0, j = -1;
	b[0] = j;
	while(i < m) {
		while((j >= 0) && (P[i] != P[j])) j = b[j];
		++i, ++j;
		b[i] = j;
	}
}

void KmpSearch() {
	int i = 0,  j = 0;
	while(i < n) {
		while ((j >= 0) && (T[i] != P[j])) j = b[j];
		++i; ++j;
		if (j == m) {
			cout << "P is found at index " << i - j << " in T\n";
			j = b[j];
		}
	}
}

int main() {
	T = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
	n = T.size();

	P = "SEVENTY SEVEN";
	m = P.size();
	KmpPreprocess();
	KmpSearch();
	cout << "-----------------------------------\n";
	NaiveMatching();

	return 0;
}
