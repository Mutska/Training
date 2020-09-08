//2020-01-06 Hangman Judge by Mutska

#include <iostream>
#include <set>
#include <string>
#include <algorithm> 

using namespace std;

int main(){

	int round;
	string answer, guess,  copy;
	set<char> bad;
	set<char>::iterator it;
	while(1){
		cin >> round;
		if(round == -1)
			break;
		cin >> answer;
		cin >> guess;
		int guess_size = guess.size();
		int hangman = 0;
		copy = answer;
		bad.clear();
		size_t found;
		for(int i = 0; i < guess_size; i++){
			found = answer.find_first_of(guess[i]);
			if(found != string::npos){
				bad.insert(guess[i]);
				copy.erase(remove(copy.begin(), copy.end(),guess[i]), copy.end());
			}else{
				it = bad.find(guess[i]);
				if(it == bad.end()){
					hangman++;
					bad.insert(guess[i]);
				}
			}
			int copy_size = copy.size();	
			if(hangman == 7 && copy_size != 0){
				cout << "Round " << round <<  "\nYou lose.\n";
					break;
			}
			if(copy_size == 0){
				cout << "Round " << round << "\nYou win.\n";
				break;
			}
			if(i + 1  == guess_size ){
				cout << "Round " << round << "\nYou chickened out.\n";
				break;
			}
				
		}
	}
	return 0;
}
