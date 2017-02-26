#include <bits/stdc++.h>
using namespace std;

// For more information:
// https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Gallai_theorem

vector<int> input; // Graph degree inputs
int N; // Vertice count

// Returns true if the degrees listed within the vector input can form a 
// valid graph. Returns false otherwise.
// Note: Make sure to remove 0's from the graph as they are unneccessary.
bool solve() {
    // Remove if the input is already sorted
    sort(input.begin(), input.end(), greater<int>());

    if (input[N-1] < 0) return false;

    vector<int> sum(N, 0);
    sum[N-1] = input[N-1];
    for (int i = N-2; i >= 0; i--)
        sum[i] = sum[i+1] + input[i];
    if (sum[0] % 2 == 1)
        return false;

    int totk = 0;
    // totk <= (k*(k+1)) + summin
    for (int k = 0; k < N; k++) {
        totk += input[k];
        int rhs = k*(k+1);
        int i;
        for (i = N-1; i > k; i--) {
            if (input[i] >= (k+1))
                break;
        }
        if (i < N-1)
            rhs += sum[i+1];
        rhs += (i - k) * (k+1);

        if (totk > rhs) return false;
    }

    return true;
}
