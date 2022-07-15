#include <iostream>
#include <vector>


using namespace std;

long long m, n;
bool execute = false;
struct guest{
	long long t, z, y;
};

vector<guest> assistant;
vector<long long> inflated;

bool good(long long time) {

	long long ballons = 0;
	bool enough = false;

	for(int i = 0; i < n; ++i) {

		long long t = time;
		long long current_inflated = 0;	
		long long total_inflated = 0;	

		if (enough) break;

		while(t > 0) {
			t -= assistant[i].t;
			if (t < 0) break;
			++current_inflated;
			++total_inflated;
			++ballons;
			if(ballons == m) {
				enough = true;
				break;
			}
			if (current_inflated == assistant[i].z) t -= assistant[i].y, current_inflated = 0;
		}
		if(execute) inflated[i] = total_inflated;
	}

	return ballons >= m;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for(int i = 0; i < n; ++i) {
		guest g;
		cin >> g.t >> g.z >> g.y;
		assistant.push_back(g);
	}

	if (m == 0) cout << "0\n0\n";
	else {

		long long l = 0; // bad
		long long r = 1; // good;

		while(!good(r)) r *= 2;


		while(r > l + 1) {
			long long time = (l + r ) / 2;
			if (good(time)) r = time;
			else l = time;
		}

		cout << r << "\n";
		inflated.assign(n, 0);
		execute = true;
		good(r);
		for(long long &i: inflated) cout << i << " ";
		cout << "\n";
	}

	return 0;
}
