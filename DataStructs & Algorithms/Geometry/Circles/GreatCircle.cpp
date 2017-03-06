#include <bits/stdc++.h>
using namespace std;

static const double PI = 2 * acos(0);

// Parameter inputs are in degrees.
double gcDistance(double pLat, double pLong,
        double qLat, double qLong, double radius) 
{
    pLat *= PI / 180.0; pLong *= PI / 180.0;
    qLat *= PI / 180.0; qLong *= PI / 180.0;
    double val = cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
            cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
            sin(pLat)*sin(qLat); 
    if (val > 1.0) val = 1.0;
    else if (val < -1.0) val = -1.0;
    return radius * acos(val);
}

