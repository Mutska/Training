//2019-12-30 Division of Nlogonia by Mutska

#include <iostream>

using namespace std;


int main(){

	int K, N, M, X, Y;


	while(1){
		cin >>  K;
		if(K == 0)
			break;
		cin >> N >> M;
		while(K--){
			cin >> X >> Y;
			
			if ((X == N && Y == M) || X == N || Y == M)
				cout << "divisa" << "\n";
			else if ( X > N && Y > M)
				cout << "NE" << "\n";
			else if ( X < N && Y > M)
				cout << "NO" << "\n";
			else if ( X < N && Y < M)
				cout << "SO" << "\n";
			else if ( X > N && Y < M)
				cout << "SE" << "\n";
		
		}
	
	
	}

	return 0;
}
