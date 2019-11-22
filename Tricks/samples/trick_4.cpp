#include <iostream>
#include <tuple>

using namespace std;


    tuple<int, string> f(void) {
   	return {485, "Quora"};
    }

int main(){
  //It’s possible to make a function that returns two or more values using std::tuple and std::tie.

   
   	int a;
    string b;

   	tie(a, b) = f();

	cout << "int a is: "<< a <<endl;
	cout << "string b is: "<< b <<endl;
  

	return 0;
}
