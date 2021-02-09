#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


    struct point{
        double x, y;
        point() {x = y = 0.0;}
        point(double _x, double _y) : x(_x), y(_y){}
    };

    double dist(point p1, point p2){
        return hypot(p1.x - p2.x, p1.y = p2.y);
    }

    int get_index(const string &s){
        int size = s.size();
        for(int i = 0; i < size; ++i){
            if(isalpha(s[i])) return i;
        }
    }


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    double sqrt2 = sqrt(2);
    int map = 0;
    while(getline(cin, line)){
        if(line == "END") break;
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        string pos;
        point route;
        while(ss >> pos){
            if(pos == ".") break;
            int cut = get_index(pos);
            double step = (double)stoi(pos.substr(0, cut));
            string dir  = pos.substr(cut);
            if(dir.back() == '.') dir.pop_back();
            if(dir == "N") route.y += step;
            if(dir == "S") route.y -= step;
            if(dir == "E") route.x += step;
            if(dir == "W") route.x -= step;
            if(dir == "NW") route.x -= (step*sqrt2)/2, route.y += (step*sqrt2)/2;
            if(dir == "NE") route.x += (step*sqrt2)/2, route.y += (step*sqrt2)/2; 
            if(dir == "SW") route.x -= (step*sqrt2)/2, route.y -= (step*sqrt2)/2; 
            if(dir == "SE") route.x += (step*sqrt2)/2, route.y -= (step*sqrt2)/2; 
        }
        point origin;
        cout << "Map #" << ++map << "\n";
        cout << "The treasure is located at (" << fixed << setprecision(3) << route.x << "," << route.y << ").\n";
        cout << "The distance to the treasure is " << dist(origin, route) << ".\n\n";
    }


    return 0;
}