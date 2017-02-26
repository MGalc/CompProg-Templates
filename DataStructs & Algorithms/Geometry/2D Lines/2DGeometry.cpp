struct point {
    double x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(double xx, double yy) : x(xx), y(yy) { }

    bool operator==(const point b) const {
        return (fabs(x - b.x) < EPS && fabs(y - b.y) < EPS);
    }
};


struct line { double a, b, c; };

line pointsToLine(point p1, point p2) {
    line l;
    if (fabs(p1.x - p2.x) < EPS) {
        // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
        // default values
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

bool areParallel(line l1, line l2) {
    // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}

bool areSame(line l1, line l2) {
    // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); 
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true; 
}

line perpendicularLineAtPoint(point p, line l) {
    point perp;
    if (fabs(l.a) > EPS) {
        perp.x = p.x + (-1.0/l.a);
        perp.y =  p.y + l.b;
    }
    else {
        perp.x = p.x;
        perp.y = p.y + 1.0;
    }
    return pointsToLine(p, perp);
}

line perpendicularLineAtPoint(point p, line l) {
    line newl = l;

    if (fabs(l.b) < EPS) {
        newl.a = 0.0;
        newl.b = 1.0;
        newl.c = p.y;
    }
    else if (fabs(l.a) > EPS) {
        newl.a = -1.0 / newl.a;
        newl.c = newl.c + (l.a - newl.a) * p.x;
    }
    else {
        newl.a = 1.0;
        newl.b = 0.0;
        newl.c = p.x;
    }
    return newl;
}

struct vect {
    double x, y;
    vect() { x = 0; y = 0; }
    vect(double xx, double yy) { x = xx; y = yy; }
};

vect toVect(point p1, point p2) {
    vect v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    return v;
}

vect toUnitVect(point p1, point p2) {
    double dist = hypot(p1.x - p2.x, p1.y - p2.y);
    vect v;
    v.x = (p2.x - p1.x)/dist;
    v.y = (p2.y - p1.y)/dist;
    return v;
}

void toUnitVect(vect& v) {
    double dist = hypot(v.x, v.y);
    v.x /= dist;
    v.y /= dist;
}

vect scale(vect v, double s) {
    // nonnegative s = [<1 .. 1 .. >1]
    return vect(v.x * s, v.y * s); 
}

// shorter.same.longer
point translate(point p, vect v) {
    // translate p according to v
    return point(p.x + v.x , p.y + v.y); 
}

double dotProduct(vect v1, vect v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double norm_sq(vect v) {
    return v.x*v.x + v.y*v.y;
}

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// returns angle aob in rad
double angle(point a, point o, point b) {
    vect oa = toVect(o, a), ob = toVect(o, b);
    return acos(dotProduct(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

double cross(vect a, vect b) {
    return a.x * b.y - a.y * b.x; 
}

// Counter clockwise test
// Returns true if r is left of line pq
bool ccw(point p, point q, point r) {
    return cross(toVect(p, q), toVect(p, r)) > 0; 
}

// checks whether points are colinear.
bool collinear(point p, point q, point r) {
    return fabs(cross(toVect(p, q), toVect(p, r))) < EPS; 
}

double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vect ap = toVect(a, p), ab = toVect(a, b);
    double u = dotProduct(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return distance(p, c); 
}
