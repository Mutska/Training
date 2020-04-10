//2020-01-04 Bender B. Rodriguez by Mutska

#include <iostream>

using namespace std;


int main(){

string current, face;

int n;

while(cin >> n){
	if(n == 0)
		break;	
	face = "+x";
	n--;
	while(n--){
		cin >> current;
		
		if(face == "+x" && current == "+y"){
			face = "+y";
			continue;
		}
		if(face == "+x" && current == "-y"){
			face = "-y";
			continue;
		}
		if(face == "+x" && current == "+z"){
			face = "+z";
			continue;
		}
		if(face == "+x" && current == "-z"){
			face = "-z";
			continue;
		}

		if(face == "-x" && current == "+y"){
			face = "-y";
			continue;
		}
		if(face == "-x" && current == "-y"){
			face = "+y";
			continue;
		}
		if(face == "-x" && current == "+z"){
			face = "-z";
			continue;
		}
		if(face == "-x" && current == "-z"){
			face = "+z";
			continue;
		}


		if(face == "+y" && current == "+y"){
			face = "-x";
			continue;
		}
		if(face == "+y" && current == "-y"){
			face = "+x";
			continue;
		}
		if(face == "+y" && current == "+z"){
			face = "+y";
			continue;
		}
		if(face == "+y" && current == "-z"){
			face = "+y";
			continue;
		}
		
		if(face == "-y" && current == "-y"){
			face = "-x";
			continue;
		}
		if(face == "-y" && current == "+y"){
			face = "+x";
			continue;
		}
		if(face == "-y" && current == "+z"){
			face = "-y";
			continue;
		}
		if(face == "-y" && current == "-z"){
			face = "-y";
			continue;
		}

		if(face == "+z" && current == "+z"){
			face = "-x";
			continue;
		}
		if(face == "+z" && current == "-z"){
			face = "+x";
			continue;
		}
		if(face == "+z" && current == "+y"){
			face = "+z";
			continue;
		}
		if(face == "+z" && current == "-y"){
			face = "+z";
			continue;
		}
		
		if(face == "-z" && current == "-z"){
			face = "-x";
			continue;
		}
		if(face == "-z" && current == "+z"){
			face = "+x";
			continue;
		}
		if(face == "-z" && current == "+y"){
			face = "-z";
			continue;
		}
		if(face == "-z" && current == "-y"){
			face = "-z";
			continue;
		}

	}
	cout << face << "\n";
}





	return 0;
}
