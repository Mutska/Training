#include <iostream>
#include <vector>


using namespace std;

struct agency{
    char name;
    int unit;
    int half;
};

int main() {
    int T;

    cin >> T;

    while(T--) {
        int M, N,L;
        cin >> M >> N >> L;
        vector<agency> Agencies;
        while(L--) {
            string line;
            agency A;
            char name;
            int unit, half;
            cin >> line;
            name = line[0];
            auto fst = line.find_first_of(":");
            auto snd = line.find_first_of(",");
            unit = stoi(line.substr(fst + 1, snd));
            half = stoi(line.substr(snd+1));
            A.name = name;
            A.unit = unit;
            A.half = half;
            Agencies.push_back(A);
        }
        for(auto &A: Agencies) {
            double n = N;
            double m = M;
            while(1) {
                
            }

        }
    }
}