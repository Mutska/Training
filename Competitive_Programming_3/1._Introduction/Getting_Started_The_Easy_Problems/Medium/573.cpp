//2020-01-02 The Snail by Mutska
#include <iostream>

using namespace std;

int main(){
	int H, U, D, F, day;
    double	initial_height, distance_climbed, height_climbing,height_sliding, fatigue;
	bool flag;
	while(1){
		day = 1;
		initial_height = 0;
		height_climbing = 0;
		distance_climbed = 0;
		height_sliding = 0;
		fatigue = 0;
		cin >> H >> U >> D >> F;
		if(H == 0)
			break;
		while(1){
			distance_climbed = 0;
			fatigue = ((double) U )* ((day - 1)*(((double) F) / 100 ));
			distance_climbed = ((double) U) - fatigue;
			if(distance_climbed >= 0){
				height_climbing = initial_height + distance_climbed;  
				flag = true;
			}else{
				flag = false;
			}
			if(height_climbing  <= 0 && day > 1){
			  	cout << "failure on day " << day << "\n";
			   	break;
			 }
			if(height_climbing > H){
			  	cout << "success on day " << day << "\n";
				break;
			}
			if(flag)
				height_sliding =  (height_climbing - D);
			else
				height_sliding -= D;
			day++;
			initial_height = height_sliding;	
			if(initial_height  <  0){
			  	cout << "failure on day " << day - 1 << "\n";
			   	break;
			 }
			if(initial_height ==  0){
			  	cout << "failure on day " << day   << "\n";
			   	break;
			 }

		}

				
	
	
	
	}



}
