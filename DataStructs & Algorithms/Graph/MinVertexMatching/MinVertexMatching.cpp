#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// NOTE: this solution will NOT work if the graph is disconnected
// solve() will need to be called for each connected component.
// Therefore, we will need to identify connected components in the BFS.

vector<vector<int>> edges;
vector<vector<int>> dp;

int solve(int loc, bool taken) {
    if (dp[loc][taken] != -1) return dp[loc][taken];
    int value = taken;

    for (int i = 0; i < edges[loc].size(); i++) {
        int next = edges[loc][i];
        if (!taken) {
            value += solve(next, true);
        }
        else {
            int mini = min(solve(next, false), solve(next, true));
            value += mini;
        }
    }

    return dp[loc][taken] = value;
}

int main() {
    int N = 100;
    vector<vector<int>> adj(N, vector<int>());
    // Get input into adj
    // adj is a bidirectional graph


    edges.assign(N, vector<int>());
    // Here we want to convert adj into a direcitonal graph (edges)
    // so we can traverse through it.
    edges.assign(N, vector<int>());
    vector<bool> visited(N, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = 0; j < adj[i].size(); j++) {
            int next = adj[i][j];
            if (visited[next]) continue;
            visited[next] = true;
            edges[i].push_back(next);
            q.push(next);
        }
    }

    dp.assign(N, vector<int>(2, -1));
    // NOTE: this solution will NOT work if the graph is disconnected
    // This might be neccessary depending on the question
    //if (N == 1)
    //cout << "1" << endl;
    //else
    cout << min(solve(0, false), solve(0, true)) << endl;
}
