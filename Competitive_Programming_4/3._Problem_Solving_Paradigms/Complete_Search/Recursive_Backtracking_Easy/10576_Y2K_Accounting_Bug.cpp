#include <iostream>
#include <cstring>

using namespace std;


long long s, d;
long long months[12];
long long maximum;



void backtrack(int month){
	if (month == 12) {
		long long total = 0;
		for(long long &m: months) {
			total += m;
		}
		maximum = max(maximum, total);
		return;
	}
	for (int  i = 0; i < 2; ++i) {
		months[month] = i == 0 ? s : -d;
		if (month > 3) {
			long long current = 0;
			for(int i = month - 4; i <= month; ++i) current += months[i];
			if (current > 0) continue;
		}
		backtrack(month + 1);
	}
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> s >> d) {
		memset(months, 0, sizeof months);
		maximum = INT32_MIN;
		backtrack(0);
		if (maximum >= 0) cout << maximum << "\n";
		else cout << "Deficit\n";
	}

}
