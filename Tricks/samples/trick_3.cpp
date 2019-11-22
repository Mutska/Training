#include <iostream>
#include <set>
using  namespace std;


int main(){

	//The range-based for loop is very cool. 
	//Instead of for (int i = 0; i < v.size(); i++) you can do for (auto &e : v) where v is a vector
	//The auto keyword infer the type of the data. Useful for map and set 
    set<int> s = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    for (auto e : s)
	   	cout << e << " ";

	cout << endl;



	return 0;
}
