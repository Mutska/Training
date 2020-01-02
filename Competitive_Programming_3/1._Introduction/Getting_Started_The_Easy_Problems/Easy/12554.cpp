//2020-01-01 A Special "Happy Birthday" Song!!1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

	string song[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to",  "Rujia", "Happy", "birthday" ,"to", "you"};
	vector<string> people;
	string person;
	int n, t;
	cin >> t;
	n = t;
	while(t--){
		cin >> person;
		people.push_back(person);
	}
	if(n == 16){
		for(int i = 0; i < 16 ; i++){
			cout << people[i] << ": " << song[i] << "\n";
		}
		
	}
	if(n < 16){
		int size = people.size();
		int j = 0;
		for(int i = 0; i < 16; i++){
			if(j == size)
				j = 0;
			cout << people[j] << ": " << song[i] << "\n";
			j++;
		}
	}
	if(n > 16){
		int size = people.size();
		int j = 0, k = -1;
		for (int i = 0;	i < size ; i++){
			if(j == 16)
				j = 0;
			cout << people[i] << ": " << song[j] << "\n";
			if(k == i)
				break;
			j++;
			if(i == (size - 1) && ((j / 15) != 1)){
				i = -1;
				k = 15 - j;
			}
		
		}

	
	}

	return 0;
}
