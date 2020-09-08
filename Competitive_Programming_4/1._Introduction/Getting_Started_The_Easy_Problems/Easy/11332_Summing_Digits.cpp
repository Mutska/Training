//2019-01-01 Summing Digits by Mutska

#include <iostream>

using namespace std;

long long int answer(long long int N){
	if (N < 10)
		return N;
	long long int result = 0;
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

	long long int N, result = 0;

	while (cin >> N){
		if (N == 0)
			break;
		result = 0;
		result = answer(N);
		cout << result << "\n";
		
	}



	
}
