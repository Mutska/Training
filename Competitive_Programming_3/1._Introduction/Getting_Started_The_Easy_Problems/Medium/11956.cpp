//2020-01-05 Brainfuck by Mutska

#include <iostream>
#include <string> 
#include <iomanip>

using namespace std;

int main(){

	int memory[100];
	int T;
	string commands;
	int count = 1;
	cin >> T;
	while(T--){
		for(int i = 0; i < 100; i++)
			memory[i] = 0;
	
		cin >> commands;
		int pointer = 0;
		for(auto instruction: commands){
			if(instruction == '>')
				pointer == 99 ? pointer = 0 : pointer++;
			if(instruction == '<')
				pointer == 0 ? pointer = 99 : pointer--;
			if(instruction == '+')
				memory[pointer] == 255 ? memory[pointer] = 0 : memory[pointer] += 1;
			if(instruction == '-')
				memory[pointer] == 0 ? memory[pointer] = 255 : memory[pointer] -= 1;
		}
		
		cout << "Case " << to_string(count) << ": ";
		for(int i = 0; i < 100; i++){
			cout << internal << setfill('0') << hex << setw(2)<< uppercase <<memory[i];
			if(i != 99)
				cout << " ";
		}
			cout << endl;	
		count++;
	
	}
	return 0;
}
