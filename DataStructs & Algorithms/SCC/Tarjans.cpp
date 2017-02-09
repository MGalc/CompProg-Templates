#include <bits/stdc++.h>

using namespace std;

#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)

typedef vector<int> vi;
typedef vector<vector<int> > vii;

int V, E; // Vector count, Edge count
vii Gedges; // Adjacency list

int nextnum;
vi dfslo;
vi dfsnum;
vector<bool> onstack;
stack<int> curscc;
void Tarjans(int loc) {
    dfsnum[loc] = nextnum++;
    dfslo[loc] = dfsnum[loc];
    onstack[loc] = true;
    curscc.push(loc);
    for (int i = 0; i < Gedges[loc].sz; i++) {
        int next = Gedges[loc][i];
        if (dfsnum[next] == -1) {
            Tarjans(next);
            dfslo[loc] = min(dfslo[loc], dfslo[next]);
        }
        else if (onstack[next]) {
            dfslo[loc] = min(dfslo[loc], dfsnum[next]);
        }
    }

    if (dfslo[loc] == dfsnum[loc]) {
        while (curscc.top() != loc) {
            onstack[curscc.top()] = false;
            dfslo[curscc.top()] = dfslo[loc];
            curscc.pop();
        }
        onstack[curscc.top()] = false;
        curscc.pop();
    }
}

void GetSCCs() {
    nextnum = 0;
    dfsnum.assign(V, -1);
    dfslo.assign(V, -1);
    onstack.assign(V, false);
    curscc = stack<int>();

    for (int i = 0; i < V; i++) {
        if (dfsnum[i] == -1) {
            Tarjans(i);
        }
    }
}

// FOR CONTRACTED ADJACENCY LIST
vector<vector<bool>> G; // For creating contracted SCC list
vii dirscc; // Contracted SCC adjacency list
vi sccnodes; // Amount of nodes in each SCC

// This needs to be called AFTER GetSCCs()
void GetContractedSCCs() {
    dirscc.assign(V, vi());
    sccnodes.assign(V, 0);
    rep(i, V) {
        sccnodes[dfslo[i]]++;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < Gedges[i].sz; j++) {
            int next = Gedges[i][j];
            if (dfslo[i] == dfslo[next] || G[dfslo[i]][dfslo[next]])
                continue;
            
            // Make sure we don't add the same edge twice
            G[dfslo[i]][dfslo[next]] = true; 
            dirscc[dfslo[i]].push_back(dfslo[next]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //////////////start//////////////

    int T;
    cin >> T;
    while (T--) {
        cin >> V >> E;
        G.assign(V, vector<bool>(V, 0));
        Gedges.assign(V, vi());
        rep(i, E) {
            int a, b;
            cin >> a >> b;
            Gedges[a-1].push_back(b-1);
        }

        // Calculates the SCCs. (each index in dfslo shows what SCC the node is in)
        GetSCCs();

        // This needs to be called AFTER GetSCCs()
        GetContractedSCCs();
    }

    //////////////end////////////////
    return 0;
}
