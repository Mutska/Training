//2020-01-02 Request for Proposal by Mutska

#include <iostream>
#include <limits>

using namespace std;

int main(){

 	int requirements, requirements_met,proposals, count = 1;
	string trash, proposal, name;
	double temp;

	while(cin >> requirements >> proposals, (requirements || proposals)){
	
		double price = numeric_limits<double>::max();
		int best = -1;
		cin.ignore();
		int r = requirements;
		while(r--)
			getline(cin, trash);

		while(proposals--){
			getline(cin, proposal);
			cin >> temp >> requirements_met;
			
			if(requirements_met > best){
				best = requirements_met;
				name = proposal;
				price = temp;
			}
			if(requirements_met == best && temp < price){
				best = requirements_met;
				name = proposal;
				price = temp;
			}
			cin.ignore();
			while(requirements_met--)
				getline(cin, trash);		

		
		}
		if(count > 1)
			cout << "\n";
		cout << "RFP #" << count++ << "\n";
		cout << name << "\n";


	}




	return 0;
}
