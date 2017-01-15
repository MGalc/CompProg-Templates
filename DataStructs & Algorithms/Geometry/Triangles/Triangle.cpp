// Returns triangle's area
double triangleArea(double base, double height) {
    return 0.5 * base * height;
}

double triangleArea(point a, point b, point c) {
    double s = semiPerimeter(a, b, c);
    double ab = distance(a, b);
    double ac = distance(a, c);
    double bc = distance(b, c);
    return sqrt(s * (s - ab) * (s - ac) * (s - bc));
}

// a, b, c are the distances between vertices
double triangleArea(double a, double b, double c) {
    double s = (a+b+c)/2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double triangleAreaFromSemiPerim(double radius, double semiPerimeter) {
    return radius * semiPerimeter;
}

double trianglePerimeter(point a, point b, point c) {
    return distance(a, b) + distance(a, c) + distance(b, c);
}

// Size of triangle's semiperimeter
double semiPerimeter(double perimeter) {
    return perimeter / 2.0;
}

double semiPerimeter(point a, point b, point c) {
    return (distance(a, b) + distance(a, c) + distance(b, c)) / 2.0;
}

// Location of triangle's incenter
point inCenter(point a, point b, point c) {
    point p;
    p.x = (distance(a, b) * c.x + distance(a, c) * b.x + distance(b, c) * a.x) / trianglePerimeter(a, b, c);
    p.y = (distance(a, b) * c.y + distance(a, c) * b.y + distance(b, c) * a.y) / trianglePerimeter(a, b, c);
    return p;
}

double incircleRadius(double area, double semiperimeter) {
    return area/semiperimeter;
}

double incircleRadius(point a, point b, point c) {
    return area(a, b, c) / semiPerimeter(a, b, c);
}

double circumcenterRadius(point a, point b, point c) {
    return (distance(a, b) * distance(a, c) * distance(b, c)) / (4.0 * triangleArea(a, b, c));
}

// a, b, c are the distances between vertices.
double circumcenterRadius(double a, double b, double c) {
    return (a * b * c) / (4.0 * triangleArea(a, b, c));
}

point circumcenterCenter(point a, point b, point c) {
    line l1, l2;
    // compute these two angle bisectors
    line ab = pointsToLine(a, b);
    point p1((a.x+b.x)/2.0, (a.y+b.y)/2.0);
    l1 = perpendicularLineAtPoint(p1, ab);
    
    line ac;
    ac = pointsToLine(a, c);
    point p3((a.x+c.x)/2.0, (a.y+c.y)/2.0);

    l2 = perpendicularLineAtPoint(p3, ac);
    point ctr;
    areIntersect(l1, l2, ctr);
    return ctr;
}

// Returns the angle at point C
point getAngle(point a, point b, point c) {
    double A = distance(b, c), B = distance(a, c), C = distance(a, b);
    return acos((A*A + B*B - C*C) / (2 * A * B));
}
