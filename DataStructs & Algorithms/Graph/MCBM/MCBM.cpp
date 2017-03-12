#include <bits/stdc++.h>
using namespace std;

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

// MAKE SURE TO ASSIGN LHS & RHS
int MCBM(int maxdist) {
    int totNodes = LHS.size() + RHS.size();
    bigraph.assign(totNodes, vector<int>());
    parents.assign(totNodes, -1);

    for (int i = 0; i < LHS.size(); i++) {
        for (int j = 0; j < RHS.size(); j++) {
            // Add if statement here
            bigraph[i].push_back(LHS.size()+j);
        }
    }

    int matched = 0;
    for (int i = 0; i < LHS.size(); i++) {
        visited.assign(totNodes, false);
        matched += match(i);
    }

    return matched;
}
