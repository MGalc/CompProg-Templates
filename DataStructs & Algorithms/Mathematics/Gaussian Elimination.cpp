#include <bits/stdc++.h>
using namespace std;

// For example,
// 1X + 2Y + 3Z = 9
// 4X + 5Y + 6Z = 8
// 9X + 8Y + 7Z = 0
// xvals = { {1, 2, 3}, {4, 5, 6}, {9, 8, 7} }
// colvals = { 9, 8, 0 }
// Make sure there are as many (or more) rows as there are rows in xvals as there are columns.

vector<vector<double>> xvals; // The matrix which contains the coefficients of the unknown values.
vector<double> colvals; // The right hand side of the equation for the current row
vector<double> avals; // The solutions for all the unknown values in x.

void gaussian() {
    for (int r = 0; r < xvals.size()-1; r++) {
        int largest = r;
        for (int i = r + 1; i < xvals.size(); i++) {
            if (fabs(xvals[i][r]) > fabs(xvals[largest][r]))
                largest = i;
        }
        swap(xvals[largest], xvals[r]);
        swap(colvals[largest], colvals[r]);
        for (int i = r+1; i < xvals.size(); i++) {
            double ratio = (double)xvals[i][r] / xvals[r][r];
            for (int j = r; j < xvals.size(); j++) {
                xvals[i][j] -= xvals[r][j] * ratio;
            }
            colvals[i] -= colvals[r] * ratio;
        }
    }

    avals.assign(xvals.size(), 0);
    for (int i = xvals.size()-1; i >= 0; i--) {
        double otherval = 0.0;
        for (int j = xvals[i].size()-1; j > i; j--) {
            otherval += avals[j] * xvals[i][j];
        }

        avals[i] = (colvals[i] - otherval) / xvals[i][i];
    }
}
