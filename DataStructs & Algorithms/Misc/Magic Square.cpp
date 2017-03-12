#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;


// A magic square is a (hopefully odd length) square
// where all rows and columns add to the same value.
// An example of a magic square with sides of length 5 is:
// 17 24 1  8  15
// 23 5  7  14 16
// 4  6  13 20 22
// 10 12 19 21 3
// 11 18 25 2  9
// 
// The solution is to start at the top row and at the center column.
// We then move northwest, wrapping around to the bottom or left
// if we reach an edge.
// If we've already taken a value and it should be our next square,
// we will instead move one step south.

vii magicsquare(int N) {
        vii result(N, vi(N, -1));

        int xloc = 0;
        int yloc = N/2;
        int curval = 1;
        for (int i = 0; i < N*N; i++) {
            result[xloc][yloc] = curval++;
            
            // Move northeast (north = towards zero for x)
            int nextx = xloc-1, nexty = yloc+1;
            if (nextx < 0) {
                nextx = N-1;
            }
            if (nexty >= N) {
                nexty = 0;
            }

            // If we've updated it before, move south.
            if (result[nextx][nexty] != -1) {
                nextx = xloc+1;
                nexty = yloc;
                if (nextx >= N)
                    nextx = 0;
            }
            xloc = nextx;
            yloc = nexty;
        }

        // The total sum of each row and column of the magic square
        int totsum = 0;
        for (int i = 0; i < N; i++)
            totsum += result[0][i]; 

        return result;
}
