//2020-01-03 Love Calculator by Mutska

#include <iostream>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

int answer(int N){
	if (N < 10)
		return N;
	int result = 0;
	while(N > 9){
		result += N % 10;
		N = N / 10;
		if(N < 10)
			result += N;
	}
	if(result > 9)
		return answer(result);
	else
		return result;
}
	

int main(){
	char values[26] = {'a','b','c','d','e','f','g','h','i','j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t','u', 'v','w', 'x', 'y', 'z'};
	int count = 1, size, one, two, c, d;
	string a, b;
	double result;
	while(getline(cin,a)){
		if(count % 2 != 0){
			b = a;
			count++;	
			continue;
		}
		size = a.size();
		one = 0;
		two = 0;
		for(int i = 0; i < size; i++){
			for(int j = 0; j < 26; j++){
				if(tolower(a[i]) == values[j]){
					one += j + 1;
					break;
				}
			}	
		}
		size = b.size();
		for(int i = 0; i < size; i++){
			for(int j = 0; j < 26; j++){
				if(tolower(b[i]) == values[j]){	
					two += j + 1;
					break;
				}	
			}
		}
		c = answer(one);
		d = answer(two);
		result = ((double)min(c,d)/(double)max(c,d));
		cout << fixed  << setprecision(2) <<result*100 << " %\n"; 
		count++;	
	}




	return 0;
}
