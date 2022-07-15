#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

long long m, n;

struct guest{
	long long t, z, y;
	
	bool const operator==(const guest &g) const {
		return t == g.t && z == g.z && y == g.y;
	}

	bool const operator<(const guest &g) const {
		return t < g.t;
	}

	friend ostream& operator<<(ostream &out, guest const &g) {
		out << g.t;
		out << " ";
		out << g.z;
		out << " ";
		out << g.y;
		out << "\n";
		return out;
	}
};

map<guest, long long> index;
vector<guest> assistant;
vector<long long> inflated;

bool good(long long time) {

	long long ballons = 0;

	for(long long i = 0; i < n; ++i) {

		long long t = time;
		long long current_inflated = 0;	
		long long total_inflated = 0;	

		while(t > 0) {
			t -= assistant[i].t;
			if (t < 0) break;
			++current_inflated;
			++total_inflated;
			++ballons;
			if (current_inflated == assistant[i].z) t -= assistant[i].y, current_inflated = 0;
		}
		inflated[index[assistant[i]]] = total_inflated;
	}
	return ballons >= m;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	inflated.assign(n, 0);

	for(int i = 0; i < n; ++i) {
		long long t, z, y;
		cin >> t >> z >> y;
		assistant.push_back({t, z, y});
		index[{t, z, y}] = i;
	}

	if (m == 0) cout << "0\n0\n";
	else {

		sort(assistant.begin(), assistant.end());

		long long l = 0; // bad
		long long r = 1; // good;

		while(!good(r)) r *= 2;


		while(r > l + 1) {
			long long time = (l + r ) / 2;
			if (good(time)) r = m;
			else l = m;
		}

		cout << r << "\n";
		good(r);
		for(long long &i: inflated) cout << i << " ";
		cout << "\n";
	}

	return 0;
}
