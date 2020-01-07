//2020-01-06 Mine sweeper by Mutska

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	
	string field[100][100];
	vector<pair<int,int>> mines;
	int n, m, T;
	string square;
	int count = 1;
	cin >> T;
	while(T--){
		cin >> n;	
		m = n;
		if(count > 1)
			cout << "\n";
		mines.clear();
		for(int i = 0 ; i < n ; i++ ){
			cin >> square;
			for(int j = 0; j < m; j++){
				if(square[j] == '*'){
					field[i][j] = square[j];
					mines.push_back(make_pair(i,j));	
				}else
					field[i][j] = '0';	
			}
		}	
		for(int i = 0 ; i < n ; i++ ){
			for(int j =0; j < m; j++){
				if(field[i][j] != "*")
					continue;

				if(field[i][j] == "*" && (i == 0 && j == 0)){
					if(field[i+1][j] != "*")
						field[i + 1][j]     = to_string( stoi(field[i+1][j]) + 1);
					if(field[i][j+1] != "*")
						field[i][ j+1 ]     = to_string( stoi(field[i][j+1]) + 1);
					if(field[i+1][j+1] != "*")
						field[i + 1][j + 1] = to_string( stoi(field[i+1][j + 1]) + 1);
					continue;
				}
				if(field[i][j] == "*" && (i == n - 1 && j == 0)){
					if(field[i-1][j] != "*")
						field[i - 1][j]     = to_string( stoi(field[i-1][j]) + 1);
					if(field[i][j+1] != "*")
						field[i][ j+1 ]     = to_string( stoi(field[i][j+1]) + 1);
					if(field[i-1][j+1] != "*")
						field[i - 1][j + 1] = to_string( stoi(field[i-1][j + 1]) + 1);
					continue;
				}
				if(field[i][j] == "*" && (i == 0 && j == m - 1)){
					if(field[i+1][j] != "*")
						field[i + 1][j]     = to_string( stoi(field[i+1][j]) + 1);
					if(field[i][j-1] != "*")
						field[i][ j - 1 ]   = to_string( stoi(field[i][j-1]) + 1);
					if(field[i+1][j-1] != "*")
						field[i + 1][j - 1] = to_string( stoi(field[i+1][j - 1]) + 1);
					continue;
				}
				if(field[i][j] == "*" && (i == n -1 && j == m -1)){
					if(field[i-1][j] != "*")
						field[i - 1][j]     = to_string( stoi(field[i-1][j]) + 1);
					if(field[i][j-1] != "*")
						field[i][ j-1 ]     = to_string( stoi(field[i][j-1]) + 1);
					if(field[i-1][j-1] != "*")
						field[i - 1][j - 1] = to_string( stoi(field[i-1][j - 1]) + 1);
					continue;
				}
				if(field[i][j] == "*" && (j == 0)){
					if(field[i-1][j] != "*")
						field[i - 1][j]   = to_string( stoi(field[i-1][j]) + 1);
					if(field[i+1][j] != "*")
						field[i + 1][j]   = to_string( stoi(field[i+1][j]) + 1);
					if(field[i][j+1] != "*")
						field[i][ j+1 ]   = to_string( stoi(field[i][j+1]) + 1);
					if(field[i-1][j+1] != "*")
						field[i-1][ j+1 ] = to_string( stoi(field[i-1][j+1]) + 1);
					if(field[i+1][j+1] != "*")
						field[i+1][ j+1 ] = to_string( stoi(field[i+1][j+1]) + 1);
					continue;
				}
				if(field[i][j] == "*" && (i == 0)){
					if(field[i][j-1] != "*")
						field[i ][j - 1]  = to_string( stoi(field[i][j-1]) + 1);
					if(field[i][j+1] != "*")
						field[i ][j + 1]  = to_string( stoi(field[i][j+1]) + 1);
					if(field[i+1][j] != "*")
						field[i+1][ j ]   = to_string( stoi(field[i+1][j]) + 1);
					if(field[i+1][j+1] != "*")
						field[i+1][ j+1 ] = to_string( stoi(field[i+1][j+1]) + 1);
					if(field[i+1][j-1] != "*")
						field[i+1][ j-1 ] = to_string( stoi(field[i+1][j-1]) + 1);
					continue;
				}
				if(field[i][j] == "*" && (j == m-1)){
					if(field[i-1][j] != "*")
						field[i - 1][j]   = to_string( stoi(field[i-1][j]) + 1);
					if(field[i+1][j] != "*")
						field[i + 1][j]   = to_string( stoi(field[i+1][j]) + 1);
					if(field[i][j-1] != "*")
						field[i][ j-1 ]   = to_string( stoi(field[i][j-1]) + 1);
					if(field[i-1][j-1] != "*")
						field[i-1][ j-1 ] = to_string( stoi(field[i-1][j-1]) + 1);
					if(field[i+1][j-1] != "*")
						field[i+1][ j-1 ] = to_string( stoi(field[i+1][j-1]) + 1);
					continue;
				}
				if(field[i][j] == "*" && (i == n-1)){
					if(field[i][j-1] != "*")
						field[i ][j - 1]  = to_string( stoi(field[i][j-1]) + 1);
					if(field[i][j+1] != "*")
						field[i ][j + 1]  = to_string( stoi(field[i][j+1]) + 1);
					if(field[i-1][j] != "*")
						field[i-1][ j ]   = to_string( stoi(field[i-1][j]) + 1);
					if(field[i-1][j+1] != "*")
						field[i-1][ j+1 ] = to_string( stoi(field[i-1][j+1]) + 1);
					if(field[i-1][j-1] != "*")
						field[i-1][ j-1 ] = to_string( stoi(field[i-1][j-1]) + 1);
					continue;
				}
				if(field[i][j] == "*" ){
					if(field[i+1][j] != "*")
						field[i+1][ j ]   = to_string( stoi(field[i+1][j]) + 1);
					if(field[i+1][j+1] != "*")
						field[i+1][ j+1 ] = to_string( stoi(field[i+1][j+1]) + 1);
					if(field[i+1][j-1] != "*")
						field[i+1][ j-1 ] = to_string( stoi(field[i+1][j-1]) + 1);
					if(field[i][j-1] != "*")
						field[i ][j - 1]  = to_string( stoi(field[i][j-1]) + 1);
					if(field[i][j+1] != "*")
						field[i ][j + 1]  = to_string( stoi(field[i][j+1]) + 1);
					if(field[i-1][j] != "*")
						field[i-1][ j ]   = to_string( stoi(field[i-1][j]) + 1);
					if(field[i-1][j+1] != "*")
						field[i-1][ j+1 ] = to_string( stoi(field[i-1][j+1]) + 1);
					if(field[i-1][j-1] != "*")
						field[i-1][ j-1 ] = to_string( stoi(field[i-1][j-1]) + 1);
					continue;
				}
							
			}
		}

		bool flag = false;	
		for(int i = 0 ; i < n ; i++ ){
			cin >> square;
			for(int j = 0; j < m; j++){
				if(square[j] == 'x' && field[i][j] == "*")
					flag = true;
				if(square[j] == '.')
					field[i][j] = ".";
			}
		}	
		if(flag)
			for(auto m: mines)
				field[m.first][m.second] = "*";
		
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << field[i][j];
			}	
			cout << "\n";
		
		}
		count++;

	}

	return 0;
}
