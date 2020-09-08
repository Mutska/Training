//2020-01-14 Box of Bricks by Mutska

#include <iostream>
#include <cmath>
using namespace std;
int main(){
ios::sync_with_stdio(0);
int N, temp, stack, average, i, result, counter, n[50];
counter = 1;
while(cin >> N, (N || false)){
	temp = N;
	average = result = i = 0;
	while(N--){
		cin >> stack;
		n[i] = stack;
		average += stack;
		i++;
	}
	average /= temp;
	for(int i = 0; i < temp; i++)
		result += abs(n[i] - average);
	cout << "Set #" << counter << "\nThe minimum number of moves is " << result / 2 << ".\n\n";
	counter++;

}



}
