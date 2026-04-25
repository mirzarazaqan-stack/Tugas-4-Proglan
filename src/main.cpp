#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "include/point2d.hpp"
#include "include/triangles.hpp" 
using namespace std;

namespace MirzaGeometry {
    void EvaluateTriangles(vector<Triangle>& triangles) {
        for (size_t i = 0; i < triangles.size(); i++) {
            triangles[i].TriangleType();
        }
    }
}

int main(int argc, char ** argv)
{
    vector<Triangle> triangles;
    
    float x1, y1, z1, x2, y2, z2, x3, y3, z3;

    while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3) {
        Point2D p1(x1, y1, z1);
        Point2D p2(x2, y2, z2);
        Point2D p3(x3, y3, z3);
        Triangle t(p1, p2, p3);
        triangles.push_back(t);
    }
    
    MirzaGeometry::EvaluateTriangles(triangles);

    return 0;
}
//contoh input 
//0 0 0 3 0 0 0 4 0
//0 0 0 4 0 0 2 3 0
//0 0 0 2 0 0 1 1.73205 0
//0 0 0 5 0 0 1 2 3^Z
//contoh output
//siku-siku
//sama kaki
//sama sisi
//sembarang