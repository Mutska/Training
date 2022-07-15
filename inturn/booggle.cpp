#include <iostream>
#include <vector>



using namespace std;

string boggle[4] = { "ICPC" , "GCPC" , "ICPC" , "GCPC" };
string res;
bool used[4][4] = {false};
int n, total_words, total_score;

int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int score(int n) {
	if (n == 3 || n == 4) return 1;
	if (n == 5) return 2;
	if (n == 6) return 3;
	if (n == 7) return 5;
	if (n == 8) return 11;
	return 0;
}

bool backtrack(int r, int c, string &s, int i) {
	if (r < 0 || r >= 4) return false;
	if (c < 0 || c >= 4) return false;
	if (boggle[r][c] != s[i]) return false;
	if (i == n - 1) {
		//cout << "I have found " << s << " in the boggle\n";
		++total_words;
		total_score += score(n);
		if (n > res.size()) res = s;
		if (n == res.size()){
			if (s < res) res = s;
		}
		return true;
	}

	used[r][c] = true;
	bool found = false;
	for(int d = 0; d < 8; ++d) {
		if(!(used[r+dr[d]][c + dc[d]])) found |= backtrack(r + dr[d], c + dc[d], s, i + 1);
		if(found) break;
	}
	used[r][c] = false;
	return found;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int w, b;
	cin >> w;
	vector<string> words;// = {"ICPC", "ACM", "CONTEST", "GCPC", "PROGRAMM"};
	string p;
	while(w--) {
		cin >> p;
		words.push_back(p);
	}
	cin >> b;
	while(b--) {

		cin >> boggle[0];
		cin >> boggle[1];
		cin >> boggle[2];
		cin >> boggle[3];

		total_words = 0;
		total_score = 0;
		res = "";
		for(string &s: words) {
			n = s.size();
			bool found = false;
			for(int i = 0; i < 4; ++i) {
				for(int j = 0; j < 4; ++j) {
					found = backtrack(i,j, s, 0);
					if(found) break;
				}
				if(found) break;
			}
		}
		cout << total_score << " " << res << " " << total_words << "\n";

	}
		
	return 0;
}
