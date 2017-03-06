#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define INF 1e9

// In the future, it would be best if every edge pair (bidirectional) 
// was labeled so reversing the flow (adding flow to the opposite direction)
// was faster than iterating over all edges (within DFS).

vector<vpii> edgevals;
int S;
int T;
int wantedFlow; // Optional value if we are making sure our flow is atleast this number
vi bfsindx;
int maxsize;

int dinicBFS() {
    bfsindx.assign(maxsize, -1);
    queue<int> q;
    q.push(S);
    bfsindx[S] = 0;
    while (!q.empty()) {
        int loc = q.front();
        q.pop();
        for (int i = 0; i < edgevals[loc].size(); i++) {
            pii nextedge = edgevals[loc][i];
            if (bfsindx[nextedge.first] == -1 && nextedge.second > 0) {
                bfsindx[nextedge.first] = bfsindx[loc] + 1;
                q.push(nextedge.first);
            }
        }
    }
    return bfsindx[T]; 
}

vector<bool> visited;
int dinicDFS(int loc, int availFlow) {
    if (visited[loc]) 
        return 0;
    visited[loc] = true;

    if (loc == T) {
        return availFlow;
    }

    int thisbfs = bfsindx[loc];
    int flowed = 0;
    for (int i = 0; i < edgevals[loc].size(); i++) {
        int nextedge = edgevals[loc][i].first;
        int nextweight = edgevals[loc][i].second;
        if (bfsindx[nextedge] == thisbfs+1 && nextweight > 0) {
            int thisflow = dinicDFS(nextedge, min(availFlow, nextweight));
            edgevals[loc][i].second -= thisflow;
            int best = 0;
            for (int j = 0; j < edgevals[nextedge].size(); j++) {
                if (edgevals[nextedge][j].first == loc &&
                        edgevals[nextedge][j].second == -nextweight) {
                    edgevals[nextedge][i].second += thisflow;
                    break;
                }
            }
            flowed += thisflow;
            availFlow -= thisflow;
            if (availFlow <= 0) // We have run out of flow. Go back.
                break;
        }
    }

    return flowed;
}

// NOTE: This version does not store an adjacency grid.
// Each node has it's own edges, thus when reversing the flow
// it needs to iterate over all the edges of the next node.
//
// This should be used for questions where the number of vertexes is too large for a adj grid.
// Also note that if the number of vertexes is high, the total amount of flow from S
// should be minimal to avoid a TLE.
bool dinics() {
    int flowed = 0;
    while (dinicBFS() > 0) {
        visited.assign(edgevals.size(), false);
        flowed += dinicDFS(S, INF);
    }

    return flowed == wantedFlow;
}
