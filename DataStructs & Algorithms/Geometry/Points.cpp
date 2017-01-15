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

// NOTE: Rotates it counter clockwise
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);
    // multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
            p.x * sin(rad) + p.y * cos(rad));
}

struct point_i {
    int x, y;
    point_i() {
        x = 0;
        y = 0;
    }
    point_i(int xx, int yy) : x(xx), y(yy) { }

    bool operator<(const point b) const {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
    bool operator>(const point b) const {
        return b < *this;
    }
    bool operator==(const point b) const {
        return (x == b.x && y == b.y);
    }
};

double distance(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
