/* Given the distinct and valid birthdays of n people as triples
 * (DD, MM, YYYY) order them first by ascending birth months (MM), then
 * by ascending birth days (DD), and finally by ascending age(this means greater years go first).
 *
 * */
#include <bits/stdc++.h> 
using namespace std;
typedef tuple<int, int, int> iii;

int main() {
	vector<iii> birthdays;

	birthdays.emplace_back(5, 24, -1980);
	birthdays.emplace_back(5, 24, -1982);
	birthdays.emplace_back(11, 13, -1983);

	sort(birthdays.begin(), birthdays.end());

	for(auto &x: birthdays)
		printf("%d %d %d\n", get<0>(x), get<1>(x),-get<2>(x));


}
