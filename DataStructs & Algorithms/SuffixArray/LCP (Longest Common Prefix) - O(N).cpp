vector<int> LCP;

// Will only work if RA has everything individually ranked.
void buildLCP(const string& suffixStr) {
    vector<int> prevInSA(SA.size());
    LCP.resize(SA.size());
    prevInSA[SA[0]] = -1;
    for (int i = 1; i < SA.size(); i++)
        prevInSA[SA[i]] = SA[i-1];

    int matched = 0;
    for (int i = 0; i < SA.size(); i++) {
        if (prevInSA[i] == -1) {
            LCP[RA[i]] = 0;
            continue;
        }
        while (suffixStr[i + matched] == suffixStr[matched + prevInSA[i]])
            matched++;

        LCP[RA[i]] = matched;
        matched = max(0, matched-1);
    }
}
