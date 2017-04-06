#include <bits/stdc++.h>
using namespace std;

map<int, string> ItoR {
    { 1, "I" },
    { 4, "IV" },
    { 5, "V" },
    { 9, "IX" },
    { 10, "X" },
    { 40, "XL" },
    { 50, "L" },
    { 90, "XC" },
    { 100, "C" },
    { 400, "CD" },
    { 500, "D" },
    { 900, "CM" },
    { 1000, "M" }
};

map<char, int> RtoI {
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
};

string romanToInt(const string& r) {
    int value = 0;
    for (int i = 0; i < r.size(); i++) {
        int nval = RtoI[r[i]];
        if (i != r.size()-1) {
            int nval2 = RtoI[r[i+1]];
            if (nval2 > nval) {
                nval = nval2 - nval;
                i++;
            }
        }
        value += nval;
    }
    return to_string(value);
}

string intToRoman(const string& v) {
    int val = stoi(v);
    string roman;
    for (auto it = ItoR.rbegin(); it != ItoR.rend(); it++) {
        while (it->first <= val) {
            roman += it->second;
            val -= it->first;
        }
    }

    return roman;
}
