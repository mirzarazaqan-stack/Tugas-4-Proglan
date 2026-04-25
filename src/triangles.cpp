#include "include/triangles.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

Triangle::Triangle() {}
Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3) : _t1(t1), _t2(t2), _t3(t3) {}

void Triangle::SetT1(Point2D t1) { _t1 = t1; }
void Triangle::SetT2(Point2D t2) { _t2 = t2; }
void Triangle::SetT3(Point2D t3) { _t3 = t3; }

void Triangle::TriangleType() {
    float d1 = _t1.distanceSquared(_t2);
    float d2 = _t2.distanceSquared(_t3);
    float d3 = _t3.distanceSquared(_t1);
    float sides[3] = {d1, d2, d3};
    sort(sides, sides + 3);
    float eps = 1e-4; 

    bool samaSisi = (abs(sides[0] - sides[1]) < eps) && (abs(sides[1] - sides[2]) < eps);
    bool samaKaki = (abs(sides[0] - sides[1]) < eps) || (abs(sides[1] - sides[2]) < eps);
    bool sikuSiku = abs((sides[0] + sides[1]) - sides[2]) < eps; 

    if (samaSisi) {
        cout << "sama sisi\n";
    } else if (sikuSiku) {
        cout << "siku-siku\n";
    } else if (samaKaki) {
        cout << "sama kaki\n";
    } else {
        cout << "sembarang\n";
    }
}