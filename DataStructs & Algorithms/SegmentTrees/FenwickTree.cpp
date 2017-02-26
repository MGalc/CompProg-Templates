#include <bits/stdc++.h>
using namespace std;

// Pretty beta version, could be improved.

class Fenwick {
private:
    inline int LoBit(int val) {
        return val & -val;
    }

public:
    vector<int> tree;
    Fenwick(vector<int>& values) {
        tree.assign(values.size()+1, 0);

        for (int i = 1; i < tree.size(); i++) {
            adjust(i, values[i-1]);
        }
    }
    Fenwick(int n) {
        tree.assign(n + 1, 0);
    }

    void adjust(int loc, int value) {
        for (int i = loc; i < tree.size(); i += LoBit(i)) {
            tree[i] += value;
        }
    }

    // Returns cumulative values between lo and hi inclusive.
    int getValue(int lo, int hi) {
        return getValueFromStart(hi) - (lo == 0 ? 0 : getValueFromStart(lo-1));
    }

    // Gets a value at a single location.
    int getValueSingle(int loc) {
        return getValue(loc, loc);
    }

    // Returns the cumulative value from 0 - loc.
    int getValueFromStart(int loc) {
        int total = 0;
        while (loc != 0) {
            total += tree[loc];
            loc -= LoBit(loc);
        }
        return total;
    }

};
