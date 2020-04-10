//2020-01-08 LC-Display by Mutska

#include <iostream>

using namespace std;

int main(){

	
	int s;
	string number;
	int size;
	while(cin >> s >> number){
		if(s  == 0 && number[0] == '0')
			break;
		size = number.size();
		for(int i = 0; i < 2*s + 3; i++ ){
			for(int j = 0; j < size; j++){
				if(number[j] == '0' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(k == 0 || k + 1 == s + 2 ){
							cout << " ";
						}else{
							cout << "-";
						}
					}
				}
				if(number[j] == '0' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if((k == 0 || k + 1 == s + 2) && i != s + 1 ){
							cout << "|";
						}else{
							cout << " ";
						}
					}
				}
				if(number[j] == '1' && (i == 0  || i + 1 ==  2*s + 3)){	
					for(int k = 0; k < s + 2 ; k++)
						cout << " ";
				}
				if(number[j] == '1' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++)
						if( k + 1 == s + 2 && i != s + 1)
							cout << "|";
						else
							cout << " ";
				}
				if(number[j] == '2' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(k == 0 || k + 1 == s + 2 ){
							cout << " ";
						}else{
							cout << "-";
						}
					}
				}
				if(number[j] == '2' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if(i < s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i < s + 1 && k + 1 == s + 2))
							cout << "|";
						if((k == 0 || k + 1 == s + 2) && i == s + 1 )
							cout << " ";
						if(k > 0  && k + 1 < s + 2 && i == s + 1 )
							cout << "-";
						if(k == 0 && i > s + 1)
							cout << "|";
						if(k > 0 && i > s + 1)
							cout << " ";
					}
				}
				if(number[j] == '3' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(k == 0 || k + 1 == s + 2 ){
							cout << " ";
						}else{
							cout << "-";
						}
					}
				}
				if(number[j] == '3' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if(i < s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i < s + 1 && k + 1 == s + 2))
							cout << "|";
						if((k == 0 || k + 1 == s + 2) && i == s + 1 )
							cout << " ";
						if(k > 0  && k + 1 < s + 2 && i == s + 1 )
							cout << "-";
						if(i > s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i > s + 1 && k + 1 == s + 2))
							cout << "|";
					}
				}
				if(number[j] == '4' && (i == 0  || i + 1 ==  2*s + 3)){	
					for(int k = 0; k < s + 2 ; k++)
						cout << " ";
				}
				if(number[j] == '4' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if(i < s + 1 && k + 1 < s + 2 && k > 0)
							cout << " ";
						if(( i < s + 1 && k  == 0))
							cout << "|";
						if(( i < s + 1 && k + 1 == s + 2))
							cout << "|";
						if((k == 0 || k + 1 == s + 2) && i == s + 1 )
							cout << " ";
						if(k > 0  && k + 1 < s + 2 && i == s + 1 )
							cout << "-";
						if(i > s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i > s + 1 && k + 1 == s + 2))
							cout << "|";
					}
				}
				if(number[j] == '5' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(k == 0 || k + 1 == s + 2 ){
							cout << " ";
						}else{
							cout << "-";
						}
					}
				}
				if(number[j] == '5' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if(i < s + 1 && k == 0)
							cout << "|";
						if( i < s + 1 && k > 0 )
							cout << " ";
						if((k == 0 || k + 1 == s + 2) && i == s + 1 )
							cout << " ";
						if(k > 0  && k + 1 < s + 2 && i == s + 1 )
							cout << "-";
						if(i > s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i > s + 1 && k + 1 == s + 2))
							cout << "|";
					}
				}
				if(number[j] == '6' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(k == 0 || k + 1 == s + 2 ){
							cout << " ";
						}else{
							cout << "-";
						}
					}
				}
				if(number[j] == '6' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if(i < s + 1 && k == 0)
							cout << "|";
						if( i < s + 1 && k > 0 )
							cout << " ";
						if((k == 0 || k + 1 == s + 2) && i == s + 1 )
							cout << " ";
						if(k > 0  && k + 1 < s + 2 && i == s + 1 )
							cout << "-";
						if(i > s + 1 && k + 1 < s + 2 && k > 0)
							cout << " ";
						if(( i > s + 1 && k + 1 == s + 2))
							cout << "|";
						if(( i > s + 1 && k  == 0))
							cout << "|";
					}
				}
				if(number[j] == '7' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(i == 0  && k > 0 && k + 1 < s + 2){
							cout << "-";
						}else{
							cout << " ";
						}
					}
				}
				if(number[j] == '7' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if(i < s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i < s + 1 && k + 1 == s + 2))
							cout << "|";
						if(i == s + 1 )
							cout << " ";
						if(i > s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i > s + 1 && k + 1 == s + 2))
							cout << "|";
					}
				}
				if(number[j] == '8' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(k == 0 || k + 1 == s + 2 ){
							cout << " ";
						}else{
							cout << "-";
						}
					}
				}
				if(number[j] == '8' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if((k == 0 || k + 1 == s + 2) && i != s + 1 ){
							cout << "|";
						}else if(i == s + 1){
							if(k == 0 || k + 1 == s + 2)
								cout << " ";
							if(k > 0  && k + 1 < s + 2)
								cout << "-";
						}else{
							cout << " ";
						}
					}
				}
				if(number[j] == '9' && (i == 0  || i + 1 == 2*s +3 )){	
					for(int k = 0; k < s + 2 ; k++){
						if(k == 0 || k + 1 == s + 2 ){
							cout << " ";
						}else{
							cout << "-";
						}
					}
				}
				if(number[j] == '9' && i > 0 && i < 2*s + 2 ){	
					for(int k = 0; k < s + 2 ; k++){
						if(i < s + 1 && k + 1 < s + 2 && k > 0)
							cout << " ";
						if(( i < s + 1 && k + 1 == s + 2))
							cout << "|";
						if( i < s + 1 && k == 0)
							cout << "|";
						if((k == 0 || k + 1 == s + 2) && i == s + 1 )
							cout << " ";
						if(k > 0  && k + 1 < s + 2 && i == s + 1 )
							cout << "-";
						if(i > s + 1 && k + 1 < s + 2)
							cout << " ";
						if(( i > s + 1 && k + 1 == s + 2))
							cout << "|";
					}
				}
				if(j < size - 1 )	
					cout << " ";
			}	
			cout << "\n";
		}
		cout << "\n";
	}



	return 0;
}
