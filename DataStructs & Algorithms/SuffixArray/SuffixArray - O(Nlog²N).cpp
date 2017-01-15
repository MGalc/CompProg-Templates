vector<int> SA;
vector<int> RA;
int gap;

bool sorter(int a, int b) {
    if (RA[a] != RA[b]) return RA[a] < RA[b];

    a += gap;
    b += gap;

    if (a < RA.size() && b < RA.size()) return RA[a] < RA[b];
    else return a < b;
}

// NOTE: suffixStr should have a delimiter at the end which is smaller than the rest of it.
void buildSA(const string& suffixStr) {
    SA.clear();
    RA.clear();
    gap = 1;

    for (int i = 0; i < suffixStr.size(); i++) {
        SA.push_back(i);
        RA.push_back(suffixStr[i]);
    }

    vector<int> temp(SA.size());
    while (gap < SA.size()) {
        sort(SA.begin(), SA.end(), sorter);

        temp[0] = 0;
        for (int i = 1; i < SA.size(); i++)
            temp[i] = temp[i-1] + sorter(SA[i-1], SA[i]);

        for (int i = 0; i < RA.size(); i++)
            RA[SA[i]] = temp[i];

        if (RA[SA[SA.size()-1]] == RA.size()-1) break;

        gap *= 2;
    }
    //if (RA[RA.size()] != RA.size()-1) throw "wrong";
    int breaks = 0;
}
