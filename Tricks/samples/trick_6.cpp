#include <iostream>

using namespace std;
//index++;if(index>=n)index = 0; -> index = (index + 1) % n;
//index--;if(index < 0)index = n-1 -> index = (index + n -1) % n;


int main(){

	int example[10] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = 10;//length of array
	int counter = 0 ; //just to no loop
	int index = 0;
	// This is for iterate in the array over and over with the follow idea: if(index>=n) index = 0;else index++;
	while(1){
	cout << example[index] << " ";	
	index = (index + 1 ) % n;
	counter++;
	if(counter == 22)
		break;
	}
	cout << endl;

	// This is for iterate in the array over and over with the follow idea: if(index < 0) index = n-1;else index--;
	counter = 0;
	index = 9;
	while(1){
	cout << example[index] << " ";	
	index = (index + n -1 ) % n;
	counter++;
	if(counter == 22)
		break;
	}
	cout << endl;



	return 0;
}
