//2019-12-30 Cost Cutting by Mutska

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int T, a, b, c, count = 1;
	vector<int> employee;
	cin >> T;

	while(T --){
			cin >> a >> b >> c;	
			employee.push_back(a);
			employee.push_back(b);
			employee.push_back(c);
			sort(employee.begin(), employee.end());
			cout << "Case " << count << ": " <<  employee[1] << "\n";
			employee.clear();
			count++;
	
	}
	


	return 0;
}
