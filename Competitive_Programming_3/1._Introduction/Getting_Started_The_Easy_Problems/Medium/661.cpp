//2020-01-02 Blowing Fuses by Mutska

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){

	int n, m, c, device_power, id;
	bitset<20> devices_set;
	vector<int> devices;
	bool flag;
	int sequence = 1;
	while(cin >> n >> m >> c){
		if((n || m || c) == 0)
			break;
		int maximum = 0;
		flag = true;
		devices_set.set();
		devices.clear();
		while(n--){
			cin >> device_power;
			devices.push_back(device_power);
		}
		while(m--){
			cin >> id;
		    int temp = 0;	
			devices_set.flip(id - 1);
			int size = devices.size();
			for(int i = 0; i < size; i++){
				if(!devices_set[i])
					temp += devices[i];
				if(temp > c)
					flag = false;
				maximum = max(maximum, temp);
			}
		}		
		
		if(flag){
			cout << "Sequence "<< sequence << "\nFuse was not blown.\nMaximal power consumption was " << maximum << " amperes.\n\n";
		}else{
			cout << "Sequence "<< sequence << "\nFuse was blown.\n\n";
		}
		sequence++;
		
	}



	return 0;
}
