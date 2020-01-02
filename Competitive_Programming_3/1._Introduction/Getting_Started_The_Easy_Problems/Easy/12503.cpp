//2020-02-02 Robot Instructions by Mutska
#include <iostream>
#include <string>

using namespace std;

int main(){
	int moves[102];
	string move, temp;
	int T, n, count, position, number, space;
	cin >> T;
	while(T--){
		count = 1;
		position = 0;
		cin >> n;
		cin.ignore();
		while(n--){
			getline(cin, move);
			if(move[0] == 'L'){
				moves[count] = -1;
				position += -1;
			}
			if(move[0] == 'R'){
				moves[count] = 1;
				position += 1;
			}
			if(move[0] == 'S'){
				space = move.find_last_of(" ");	
				number = stoi(move.substr(space + 1));
				moves[count] = moves[number];
				position += moves[number];
			}
			count++;
		
		}
		cout << position << "\n";
	
	}


	return 0;
}
