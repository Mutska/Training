//2020-01-01 Event Planning by Mutska

#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std;

int main(){

	int N, B, H, W, w,  p, a;
	bool result;
	int price;

	while( cin >> N >> B >> H >> W){
		price = 10000*200;
		result = false;
		while(H--){
			cin >> p;
			w = W;
			while(w--){
				cin >> a;
				if(N > a){
					if(result == true)
						continue;
					result = false;
				}else{
					result = true;
					if(p*N <= price)
						price = p*N;
				}
			}	
			if(price > B)
				result = false;
		}
		if(result)
			cout << price << "\n";
		else
			cout << "stay home" << "\n";	
	
	}


	return 0;
}
