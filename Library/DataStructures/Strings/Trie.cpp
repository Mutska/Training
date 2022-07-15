#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;


struct vertex {
	char alphabet;
	bool exist;
	int pc; // No. of words with this prefix
	vector<vertex*> child;
	vertex(char a): alphabet(a), exist(false), pc(1) { child.assign(26, NULL); }
};

class Trie {
	private:
		vertex * root;

	public:
		Trie() { root = new vertex('!'); }

	
	void insert(string word) { // insert a word into trie
		vertex * cur = root;
		for (int i = 0; i < (int) word.size(); ++i) {
			int alphaNum = word[i] - 'a';
			if(cur->child[alphaNum] == NULL) cur->child[alphaNum] = new vertex(word[i]); // add new branch if NULL
			else cur->child[alphaNum]->pc++;
			cur = cur->child[alphaNum];
		}
		cur->exist = true;
	}

	bool search(string word) {
		vertex * cur  = root;
		for(int i = 0; i < (int) word.size(); ++i) {
			int alphaNum = word[i] - 'a';
			if (cur->child[alphaNum] == NULL) return false; // not found
			cur = cur->child[alphaNum];
		}
		return cur->exist;
	}

	bool startsWith(string prefix) {
		vertex * cur = root;
		for (int i = 0; i < (int) prefix.size(); ++i) {
			int alphaNum = prefix[i] - 'a';
			if (cur->child[alphaNum] == NULL) return false;
			cur = cur->child[alphaNum];
		}
		return true;
	}

	int wordsWith(string prefix) {
		vertex * cur = root;
		for (int i = 0; i < (int) prefix.size(); ++i) {
			int alphaNum = prefix[i] - 'a';
			if (cur->child[alphaNum] == NULL) return 0;
			cur = cur->child[alphaNum];
		}
		return cur->pc;
	}

	void dfs(string s) {
		dfs(s, root);
	}

	void dfs (string s, vertex * v) {
		if(v->exist) {
			cout << s << " is in the Trie\n";
			return;
		}

		for(int i = 0; i < 26; ++ i) {
			if (v->child[i] != NULL) {
				s += v->child[i]->alphabet;
				dfs(s, v->child[i]);
				s.pop_back();
			}
		}
	}
	
};



int main() {

	Trie T;

	// Test 1
	//set<string> strings = {"banana", "pan", "and", "nab", "antenna", "bandana", "ananas", "nana"};
	//for(auto &s: strings) T.insert(s);
	//for(auto &s: strings) if (T.search(s)) cout << s << " is in the Trie\n";
	//cout << "-------------------------------------------------------\n";
	//set<string> prefixs = {"pa", "ban", "ant", "na", "p"};
	//for(auto &p: prefixs) if (T.startsWith(p)) cout << p << " is prefix in the Trie\n";

	// Test 2
	set<string> strings2 = {"abac", "abaa", "abab", "aabb", "aabc"};
	for(auto &s: strings2) T.insert(s);
	for(auto &s: strings2) if (T.search(s)) cout << s << " is in the Trie\n";
	cout << "-------------------------------------------------------\n";
	set<string> prefixs = {"ab", "aba", "abaa", "ac", "aa"};
	for(auto &p: prefixs) cout << "There are " << T.wordsWith(p) << " words that has the prefix " << p << "\n";

	cout << "-------------------------------------------------------\n";
	cout << "DFS on Trie:\n";

	T.dfs("");

	return 0;
}
