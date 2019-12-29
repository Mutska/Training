//2019-12-28 Combination Lock by Mutska
#include <iostream>


using namespace std;

int mod(int a, int b){
	//This works for this problem because b is >= a.
	return (((a%b) + b) % b);


}
int main(){
	
int initial, first, second, third, last;

	last = 1080;

	while(cin >> initial >> first >> second >> third){
		if((initial || first || second || third) == 0)
			break;	
		while(initial != first){
			initial--;
			last += 9;
			if(initial < 0 || initial > 39)
				initial = mod(initial, 40);
		}
		while(initial != second){
			initial++;
			last += 9;
			if(initial < 0 || initial > 39)
				initial = mod(initial, 40);
		
		}
		while(initial != third){
			initial--;
			last += 9;
			if(initial < 0 || initial > 39)
				initial = mod(initial, 40);
		}
		cout << last << "\n";
		last = 1080;
	}

	return 0;
}
