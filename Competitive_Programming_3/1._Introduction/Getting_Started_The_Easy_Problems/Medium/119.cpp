//2020-01-02 Greedy Gift Givers

#include <iostream>
#include <string>
#include <map>
#include <vector> 

using namespace std;

int main(){

map<string,pair<int, int>> people;
string person, receiver;
vector<pair <string, int>> index;
int n, temp, budget, number, net, gift, blank = 1;
while(1){
	cin >> n;
	if(cin.eof())
		break;
	else if(blank > 1)
		cout << "\n";

	temp = n;
	int count = 0;
	while(n--){
		cin >> person;
		people[person].first = count;
		people[person].second = 0;
		index.push_back(make_pair(person,0));
		count++;
	}
	while(temp--){
		cin >> person >> budget >> number;
		if(number == 0)
			net = 0;
		else
			gift = budget / number;
		net = gift * number;
		people[person].second -= net;
		while(number--){
			cin >> person;
			people[person].second += gift;
		}

	}
		for(auto p: people){
			int i  = p.second.first; 
			int res  = p.second.second;
			index[i].second = res;
		}
		for(auto i: index){
			cout << i.first << " " << i.second << "\n";
		}
		blank++;
		index.clear();
		people.clear();
	

}


	return 0;
}
