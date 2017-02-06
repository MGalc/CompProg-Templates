#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> LHS;
vector<int> RHS;
vector<vector<int>> bigraph;
vector<int> parents;
vector<bool> visited;

int match(int left) {
    if (visited[left])
        return 0;
    visited[left] = true;

    for (int i = 0; i < bigraph[left].size(); i++) {
        int right = bigraph[left][i];
        if (parents[right] == -1) {
            parents[right] = left;
            return 1;
        }
        else if (parents[right] != left) {
            if (match(parents[right]) == 1) {
                parents[right] = left;
                return 1;
            }
        }
    }

    return 0;
}

int MCBM(int maxdist) {
    bigraph.assign(N, vector<int>());
    parents.assign(N, -1);

    for (int i = 0; i < LHS.size(); i++) {
        for (int j = 0; j < RHS.size(); j++) {
            bigraph[i].push_back(LHS.size()+j);
        }
    }

    int matched = 0;
    for (int i = 0; i < LHS.size(); i++) {
        visited.assign(N, false);
        matched += match(i);
    }

    return matched;
}
