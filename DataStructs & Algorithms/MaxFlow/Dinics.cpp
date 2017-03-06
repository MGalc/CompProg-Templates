#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

#define INF 1e9

vii flowvals; // Stores the current values of flows
vii edges; // Stores the edges
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
        for (int i = 0; i < edges[loc].size(); i++) {
            if (bfsindx[edges[loc][i]] == -1 && flowvals[loc][edges[loc][i]] > 0) {
                bfsindx[edges[loc][i]] = bfsindx[loc] + 1;
                q.push(edges[loc][i]);
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
    for (int i = 0; i < edges[loc].size(); i++) {
        if (bfsindx[edges[loc][i]] == thisbfs+1 && flowvals[loc][edges[loc][i]] > 0) {
            int thisflow = dinicDFS(edges[loc][i], min(availFlow, flowvals[loc][edges[loc][i]]));
            flowvals[loc][edges[loc][i]] -= thisflow;
            flowvals[edges[loc][i]][loc] += thisflow;
            flowed += thisflow;
            availFlow -= thisflow;
            if (availFlow <= 0) // We have run out of flow. Go back.
                break;
        }
    }

    return flowed;
}

bool dinics() {
    int flowed = 0;
    while (dinicBFS() > 0) {
        visited.assign(maxsize, false);
        flowed += dinicDFS(S, INF);
    }

    // Here flowed variable is the amount which was able to flow to the end
    // Do whatever you want to it.
    return flowed == wantedFlow;
}
