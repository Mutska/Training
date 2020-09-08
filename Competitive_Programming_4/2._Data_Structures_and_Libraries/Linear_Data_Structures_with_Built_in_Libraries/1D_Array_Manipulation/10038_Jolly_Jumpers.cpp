//2020-01-14 Jolly Jumpers by mutska

#include <iostream>
#include <array>
#include <cmath>

using namespace std;
array<bool, 3000> flags;

int main() {
ios_base::sync_with_stdio(0);
int n, number, temp, size;
bool res;
while(cin >> n) {
	if (n == 1) { cin >> number;  cout << "Jolly\n"  ; continue ;} 
	flags = {false};
	res = true;
	size = n;
	cin >> number;
	temp = number;
	n--;
	while(n--) {
		cin >> number;
		flags[abs(temp - number)] = true;
		temp = number;
	}
	for(int i = 1; i < size; i++)
		if(flags[i] == false)
			res = false;
	res ? cout << "Jolly\n" : cout << "Not jolly\n";

}
}
