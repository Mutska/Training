#include <iostream>
#include <vector>
#include <iomanip>

// testing to matrix power

using namespace std;
typedef vector<vector<long double>> Matrix;
typedef vector<long double> vd;

void printMatrix(Matrix& A) {

	int n = A.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) cout  << A[i][j] << " ";
        cout << "\n";
    }
}

Matrix matrixMultiplication(Matrix a, Matrix b) {
	int n = a.size();
	Matrix ans(n, vd(n, 0));


	for(int i = 0; i < n; ++i)
		for(int k = 0; k < n; ++k) {
			if (a[i][k] == 0) continue;
			for(int j = 0; j < n; ++j){
				ans[i][j] += a[i][k] * b[k][j];
			}
		}

	return ans;
	
}

Matrix matrixPower(Matrix base, int p){

	int n = base.size();
	Matrix ans(n, vd(n, 0));
	for(int i = 0; i < n; ++i) ans[i][i] = 1;

	while(p) {
		if (p & 1) ans = matrixMultiplication(ans, base);
		base = matrixMultiplication(base, base);
		p >>= 1;
	}
	return ans;
}



int  main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    Matrix A(n, vd(n, 0));
    Matrix I(n, vd(n, 0));
	

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> A[i][j];
            if (i == j) I[i][j] = (long double) 1;
        }
    }

    //cout << "Initial A matrix:\n";
	//printMatrix(A);
	A = matrixPower(A, m);
    //cout << "Last A matrix:\n";
	//printMatrix(A);
	for(int i = 0; i < n; ++i) cout << fixed << setprecision(4) <<  A[0][i] << "\n";

    return 0;
}