#include <bits/stdc++.h>

using namespace std;

// N is number of nodes, M is number of edges
int N, M;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;

int match(int loc) {
    if (visited[loc]) 
        return 0;
    visited[loc] = true;

    for (int i = 0; i < graph[loc].size(); i++) {
        int next = graph[loc][i];
        if (parent[next] == -1) {
            parent[next] = loc;
            return 1;
        }
        else if (parent[next] != loc && match(parent[next])) {
            parent[next] = loc;
            return 1;
        }
    }

    return 0;
}

int MCBM() {
    int matches = 0;
    parent.assign(N, -1);

    for (int i = 0; i < graph.size(); i++) {
        visited.assign(N, false);
        matches += match(i);
    }

    return matches;
}

// NOTE: This Min Path Cover only works on a Directed Acyclic Graph
// Min Path Cover finds minimum amount of paths needed to cover all vertices in a graph.
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    cin >> N >> M;
    graph.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        graph[from-1].push_back(to-1);
    }

    cout << N - MCBM() << endl;

    //////////////end////////////////
    return 0;
}
