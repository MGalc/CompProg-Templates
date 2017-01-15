#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)

double circleArea(double radius) {
    return PI * radius * radius;
}

double eclipseArea(double radiusA, double radiusB) {
    return PI * radiusA * radiusB;
}

double circumferenceFromRadius(double radius) {
    return 2.0 * PI * radius;
}

double circumferenceFromDiameter(double diameter) {
    return PI * diameter;
}

double arcLength(double circumference, double angle) {
    return circumference * (angle / 360.0);
}

double chordLengthRadius(double radius, double angle) {
    return 2.0 * radius * sin(angle / 2.0);
}

double chordLengthDiameter(double diameter, double angle) {
    return diameter * sin(angle / 2.0);
}

double sectorArea(double area, double angle) {
    return area * (angle / 360.0);
}

double toRadians(double angle) {
    return angle * (PI / 180.0);
}

double toDegrees(double radians) {
    return radians * (180.0 / PI);
}

// p = point to check
// c = center of circle
// r = radius of circle
int insideCircleCheck(point_i p, point_i c, int r) { // all integer version
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; //inside/border/outside 
}

// p = point to check
// c = center of circle
// r = radius of circle
int insideCircleCheck(point p, point c, double r) {
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r;
    if (fabs(Euc - rSq) < 0) return 1; //border
    if (Euc < rSq) return 0; //inside
    return 2; //outside
} 

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; 
} // to get the other center, reverse p1 and p2
