#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

  vector<int> positive = {1,2,3,4,5};	
  vector<int> at_least = {-1,-2,-3,-4,5};	
  vector<int> none = {-1,-2,-3,-4,-5};	
	//are all elements positive?
	if(all_of(positive.begin(), positive.end(), [](int i){return i>0;}))
		cout << "Yes all elements are positive" << endl;
	//at least one positive element?
	if(any_of(at_least.begin() ,at_least.end() , [](int i){return i>0;}))
		cout << "Yes, at least one element is positive" << endl;
    //none positive? 
	if(none_of(none.begin(), none.end(), [](int i){return i>0;}))
		cout << "No one is positive" << endl;
	return 0;
}
