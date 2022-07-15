#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


int CA, CB, N;
vector<string> steps;
bool solved = false;

bool memo[1000][1000];


void bactrack(int Ca, int Cb){
	if (solved) return;
	if (memo[Ca][Cb]) return;
	memo[Ca][Cb] = 1;
	if (Cb == N) {
		solved = true;
		for(string s: steps) cout << s << "\n";
		cout << "success\n";
	}

	// Empty A
	if (Ca > 0) {
		steps.push_back("empty A");
		bactrack(0, Cb);
		steps.pop_back();
	}
	// Fill A
	if (Ca < CA){ steps.push_back("fill A");
		bactrack(CA, Cb);
		steps.pop_back();
	}
	// Pour A B
	if (Ca != 0){ 
		steps.push_back("pour A B");
		bactrack(max(Ca - (CB - Cb), 0), min(CB, Cb + Ca));
		steps.pop_back();
	}

	// Empty B
	if (CB > 0) {
		steps.push_back("empty B");
		bactrack(Ca, 0);
		steps.pop_back();
	}
	// Fill B
	if (Cb < CB){ 
		steps.push_back("fill B");
		bactrack(Ca, CB);
		steps.pop_back();
	}
	// Pour B A
	if (Ca != 0){ 
		steps.push_back("pour B A");
		bactrack(min(CA, Ca + Cb), max(Cb - (CA - Ca), 0));
		steps.pop_back();
	}

}


int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	while (cin >> CA >> CB >> N) {
		bactrack(0,0);
		memset(memo, 0, sizeof memo);
		solved = false;
	}

}
