//2019-01-05 Prerequisites? by Mutska

#include <iostream>
#include <vector>

using namespace std;

int main(){


	int k, m, c, r, course, need;
	vector<int> courses;
	bool result;
	
	while(cin >> k){
		if(k == 0)
			break;
		cin >> m;
		result = true;
		courses.clear();
		while(k--){
			cin >> course;
			courses.push_back(course);
		}

		while(m--){
			cin >> c >> r;
			need = 0;
			while(c--){
				cin >> course;
				for(auto c: courses){
					if(course == c)
						need++;
				}
			}
			if(need < r)
				result = false;
		}
		if(result)
			cout << "yes\n";
		else
			cout << "no\n";
	}



	return 0;
}
