// The Matrix Chain Multiplication problem counts the best way to 
// multiply matrices in the least amount of individual multiplicative steps possible.
//

#include <bits/stdc++.h>
using namespace std;

#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
typedef vector<pair<int,int>> vpii;
typedef vector<int> vi;
typedef vector<vector<int> > vii;

int N;
vpii input;
vii dp;
vii mid;

int solve(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j) 
        return 0;

    int minimum = numeric_limits<int>::max();
    for (int k = i; k < j; k++) {
        int solveval = solve(i, k) + solve(k+1, j)
                + input[i].first * input[k].second * input[j].second;

        if (solveval < minimum) {
            minimum = solveval;
            mid[i][j] = k; // Part of printing whole solution
        }
    }

    return dp[i][j] = minimum;
}

vi open, closed;
void getBestParentheses(int i, int j) {
    if (i == j)
        return;
    open[i]++;
    closed[j]++;

    getBestParentheses(i, mid[i][j]);
    getBestParentheses(mid[i][j]+1, j);
}

void printSolution() {
    getBestParentheses(0, N-1);

    rep(i, N) {
        if (i != 0)
            cout << " x ";
        while (open[i] > 0) {
            cout << "(";
            open[i]--;
        }
        cout << "A" << i+1;
        while (closed[i] > 0) {
            cout << ")";
            closed[i]--;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int casenum = 1;
    while (cin >> N, N) {
        cout << "Case " << casenum++ << ": ";

        input.resize(N);
        rep(i, N)
            cin >> input[i].first >> input[i].second;

        dp.assign(N, vi(N, -1));
        mid.assign(N, vi(N, -1)); // Remove if not printing whole solution.

        open.assign(N, 0);
        closed.assign(N, 0);

        solve(0, N-1);
    }
}

