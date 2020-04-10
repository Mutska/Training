//2020-01-19 Error Correction by Mutska

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int matrix [100][100];
	int n, t, a, count1,count2, sum, row, col;
	while(cin >> t, (t || false)){
		n = t;
		row = col = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				cin >> a;
				matrix[i][j] = a;
		}
		count1 = 0;
		for(int i = 0; i < n; i++){
			sum = 0;
			for(int j = 0; j < t; j++)
				sum	 += matrix[i][j];
			if(sum % 2 != 0) {count1++ ; row = i;}
		}
		count2 = 0;
		for(int i = 0; i < n; i++){
			sum = 0;
			for(int j = 0; j < t; j++)
				sum	 += matrix[j][i];
			if(sum % 2 != 0) {count2++; col = i;}
		}
		if(count1 == 0 &&  count2 == 0)
			cout << "OK\n";
		if(count1 == 1 &&  count2 == 1)
			cout << "Change bit (" << row + 1<<"," << col + 1 <<")\n";
		if(count1 > 1 || count2 > 1)
			cout << "Corrupt\n";
	}



	return 0;
}




