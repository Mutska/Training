#include <iostream>
#include <climits>
#include <string>


using namespace std;


long long nb, ns, nc, pb, ps, pc, r, B, S, C;


bool good(long long hamburgers) {


	long long b = B*hamburgers;
	long long s = S*hamburgers;
	long long c = C*hamburgers;
	long long money = r;

	if (nb < b) money -= ((b - nb) * pb);
	if (ns < s) money -= ((s - ns) * ps);
	if (nc < c) money -= ((c - nc) * pc);

	return money >= 0;
}

int main() {

	string recipe;
	cin >> recipe;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;

	int n = recipe.size();
	
	for(int i = 0; i < n; ++i) {
		if (recipe[i] == 'B') ++B;
		if (recipe[i] == 'S') ++S;
		if (recipe[i] == 'C') ++C;
	}


	long long l = 0; // good
	long long r = 10e12; // bad

	while(r > l + 1) {
		long long hamburgers = (l + r) / 2;
		if (good(hamburgers)) l = hamburgers;
		else r = hamburgers;
	}

	cout << l << "\n";

	return 0;

}
