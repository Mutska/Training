//2020-01-07 Ananagrams by Mutska

#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 
#include <map>
#include <set>

using namespace std;

int main(){

	string word, temp;
	map<string, set<string>> dictionary;
	vector<string> sorted;
	vector<string> results;
	int count = 0;
	while(1){
		cin >> word;
		if(word == "#")
			break;
		temp = word;
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		sort(word.begin(), word.end());
		sorted.push_back(word);
		dictionary[word].insert(temp);
		count++;
	}
	sort(sorted.begin(), sorted.end());
	int size = count;
	count = 0;
	while(1){
		if(size == count)
			break;
		int size, flag = 0;
		string current = sorted[count];
		size = current.size();
		if(size == 1){
			for(auto d: dictionary[current])
				results.push_back(d);
			count++;
			continue;
		}
		for(auto s: sorted){
			if(s == current)
				flag++;
			if(flag > 1)
				break;		
		}
		if(flag == 1)
			for(auto d: dictionary[current])
				results.push_back(d);
		count ++;
	}
	sort(results.begin(), results.end());
	for(auto r: results)
		cout << r << "\n";
	return 0;
}
