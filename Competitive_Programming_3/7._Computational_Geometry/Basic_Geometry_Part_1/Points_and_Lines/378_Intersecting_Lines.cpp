#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define INF 1e9
#define EPS 1e-9

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator < (point other) const { // override less than operator
    if (fabs(x-other.x) > EPS)                   // useful for sorting
      return x < other.x;          // first criteria , by x-coordinate
    return y < other.y; }          // second criteria, by y-coordinate
  // use EPS (1e-9) when testing equality of two floating points
  bool operator == (point other) const {
   return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS)); } };

 struct line { double a, b, c; };          // a way to represent a line

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x-p2.x) < EPS)                  // vertical line is fine
    l = {1.0, 0.0, -p1.x};                           // default values
  else {
    double a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
    l = {a,
         1.0,              // IMPORTANT: we fix the value of b to 1.0
         -(double)(a*p1.x) - p1.y}; }
  }

bool areParallel(line l1, line l2) {       // check coefficients a & b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) {           // also check coefficient c
  return areParallel(l1 ,l2) && (fabs(l1.c-l2.c) < EPS); }

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;            // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
  else                  p.y = -(l2.a*p.x + l2.c);
  return true; }


int  main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double x1, y1, x2, y2, x3, y3, x4, y4;
    int N;
    cin >> N;
    cout << "INTERSECTING LINES OUTPUT\n";
    while(N--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        point P1(x1,y1);
        point P2(x2,y2);
        point P3(x3,y3);
        point P4(x4,y4);
        point intersection;
        line l1, l2;
        pointsToLine(P1, P2, l1);
        pointsToLine(P3, P4, l2);
        if(areIntersect(l1, l2, intersection)){
            cout << "POINT " << fixed << setprecision(2) <<intersection.x << " " << intersection.y << "\n";
        }else if(areSame(l1, l2)) {
            cout << "LINE\n";
        }else if(areParallel(l1,l2)){
            cout << "NONE\n";
        }
        


    }
    cout << "END OF OUTPUT\n";


    return 0;
}