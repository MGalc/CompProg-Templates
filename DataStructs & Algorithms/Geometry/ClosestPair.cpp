#include <bits/stdc++.h>
using namespace std;

double dist(pair<double, double> a, pair<double, double> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

struct ysort {
    bool operator()(const pair<double, double>& a, const pair<double, double>& b) {
        if (a.second == b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

// Parameter input is the points sorted by x coords then y coords.
int getClosesPair(vector<pair<double, double>> input) {
    // We want to sort the rest by y coordinates first rather than x first.
    set<pair<double, double>, ysort> sorted;
    double bestdist = 1e9;
    for (int i = 0; i < input.size(); i++) {
        pair<double, double> loend = input[i];
        loend.second -= bestdist;
        auto search = sorted.lower_bound(loend);

        while (search != sorted.end()) {
            if (input[i].first - search->first > bestdist) {
                search = sorted.erase(search);
            }
            else if (input[i].second - search->second > bestdist) {
                break;
            }
            else {
                bestdist = min(bestdist, dist(input[i], *search));
                search++;
            }
        }
        sorted.insert(input[i]);
    }

    return bestdist;
}

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> input(N);
    for (int i = 0; i < N; i++) {
        pair<double, double> in;
        cin >> in.first >> in.second;
        input[i] = in;
    }
    sort(input.begin(), input.end());
}


