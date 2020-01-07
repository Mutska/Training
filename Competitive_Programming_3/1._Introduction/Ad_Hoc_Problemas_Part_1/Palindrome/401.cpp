//2020-01-06 Palindromes by Mutska

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	
	string word, original;
	bool isPalindrome, isMirrored;

	while(cin >> word){
		isPalindrome = isMirrored = false;
		original = word;
		reverse(word.begin(), word.end());	
		if(original == word)
			isPalindrome = true;
		reverse(word.begin(), word.end());
		int size = word.size();
		for(int i = 0; i < size; i++){
			if(word[i] == 'B'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'C'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'D'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'F'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'G'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'K'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'N'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'P'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'Q'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'R'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == '4'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == '6'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == '7'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == '9'){
				word[i] = ' ';
				continue;
			}	
			if(word[i] == 'E'){
				word[i] = '3';
				continue;
			}	
			if(word[i] == 'J'){
				word[i] = 'L';
				continue;
			}
			if(word[i] == 'L' ){
				word[i] = 'J';
				continue;
			}
			if(word[i] == 'Z' ){
				word[i] = '5';
				continue;
			}
			if(word[i] == '2' ){
				word[i] = 'S';
				continue;
			}
			if(word[i] == 'S' ){
				word[i] = '2';
				continue;
			}
			if(word[i] == '3' ){
				word[i] = 'E';
				continue;
			}
			if(word[i] == '5' ){
				word[i] = 'Z';
				continue;
			}
		}
		reverse(word.begin(), word.end());
		if(original == word)
			isMirrored = true;
		if(isPalindrome && isMirrored)
			cout << original << " -- is a mirrored palindrome.\n\n";	
		if(isPalindrome && !isMirrored)
			cout << original << " -- is a regular palindrome.\n\n";	
		if(!isPalindrome && isMirrored)
			cout << original << " -- is a mirrored string.\n\n";	
		if(!isPalindrome && !isMirrored)
			cout << original << " -- is not a palindrome.\n\n";	
	
	}



	return 0;
}
