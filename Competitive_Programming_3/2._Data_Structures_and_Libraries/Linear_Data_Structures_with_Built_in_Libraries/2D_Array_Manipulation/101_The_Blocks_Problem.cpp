//2020-01-19 The Blocks Problem by Mutska

#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;


int main() {

	int blocks[25][25], n, from, to, temp, t, row1, row2;
	stack<int> pile;
	map<int, int> position;
	string command1, command2;
	for(int i = 0; i < 25; i++)
		for(int j = 0; j < 25; j++)
			blocks[i][j] = -1;
	cin >> n;
	t = n;
	for(int i = n - 1; i >= 0; i--){
		blocks[24][i] = i;
		position[i] = i;
	}	
	while(true) {
		cin >> command1;
		if(command1 == "quit") break;
		cin >> from >> command2 >> to;
		if(from == to || position[from] == position[to]) continue;
		if(command1 == "move" && command2 == "onto"){
			for(int i = 0; i < 25;i++){
				temp  = blocks[i][position[from]];
				if(temp == from){ row1 = i; break;}
				blocks[i][position[from]] = -1;
				if(temp != -1) {blocks[24][temp] = temp; position[temp] = temp ;}
			}	
			for(int i = 0; i < 25;i++){
				temp  = blocks[i][position[to]];
				if(temp == to){ row2 = i; break;}
				blocks[i][position[to]] = -1;
				if(temp != -1) {blocks[24][temp] = temp; position[temp] = temp ;}
			}
			blocks[row1][position[from]] = -1;		
			position[from] = position[to];
			blocks[row2 -1][position[to]] = from;
		}
		if(command1 == "move" && command2 == "over"){
			for(int i = 0; i < 25;i++){
				temp  = blocks[i][position[from]];
				if(temp == from){ row1 = i; break;}
				blocks[i][position[from]] = -1;
				if(temp != -1) {blocks[24][temp] = temp; position[temp] = temp ;}
			}	
			for(int i = 0; i < 25; i++){
				if(blocks[i][position[to]] != -1){
					blocks[i-1][position[to]] = from;
					break;
				}
			}
			blocks[row1][position[from]] = -1;		
			position[from] = position[to];
		}
		if(command1 == "pile" && command2 == "onto"){
			for(int i = 0; i < 25;i++){
				temp  = blocks[i][position[to]];
				if(temp == to){ row2 = i; break;}
				blocks[i][position[to]] = -1;
				if(temp != -1) {blocks[24][temp] = temp; position[temp] = temp ;}
			}
			for(int i = 0; i < 25;i++){
				temp  = blocks[i][position[from]];
				blocks[i][position[from]] = -1;
				if(temp != -1) {pile.push(temp); position[temp] = position[to] ;}
				if(temp == from) break;
			}	
			for(int i = 24; i >=0; i--){
				if(pile.empty()) break;
				if(blocks[i][position[to]] == -1){
					blocks[i][position[to]] = pile.top();
					pile.pop();
				}
			}
			position[from] = position[to];
		}
		if(command1 == "pile" && command2 == "over"){
			for(int i = 0; i < 25;i++){
				temp  = blocks[i][position[from]];
				blocks[i][position[from]] = -1;
				if(temp != -1)  {pile.push(temp); position[temp] = position[to] ;}
				if(temp == from) break;
			}	
			for(int i = 24; i >=0; i--){
				if(pile.empty()) break;
				if(blocks[i][position[to]] == -1){
					blocks[i][position[to]] = pile.top();
					pile.pop();
				}
			}
			position[from] = position[to];
		}
	}
	for(int i = 0; i <  t; i++){
		cout << i << ":";
		for(int j = 24; j >= 0 ; j--)
			if(blocks[j][i] != -1)
				cout<< " " << blocks[j][i];
		cout << "\n";
	}


	return 0;
}
