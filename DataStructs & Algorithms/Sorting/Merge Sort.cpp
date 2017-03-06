#include <bits/stdc++.h>
using namespace std;

void mergeHalves(int lo, int hi, string& s) {
    string tmp(s.begin()+lo, s.begin()+hi+1);

    int mid = (hi-lo)/2;
    int curlo = 0, curhi = mid+1;
    for (int i = 0; i < tmp.size(); i++) {
        if (curlo > mid)
            s[lo+i] = tmp[curhi++];
        else if (curhi >= tmp.size())
            s[lo+i] = tmp[curlo++];
        else {
            if (tmp[curlo] <= tmp[curhi])
                s[lo+i] = tmp[curlo++];
            else {
                s[lo+i] = tmp[curhi++];
            }
        }
    }
}

void sortRange(int lo, int hi, string& s) {
    if (lo == hi) return;

    int mid = (lo+hi)/2;
    sortRange(lo, mid, s);
    sortRange(mid+1, hi, s);
    mergeHalves(lo, hi, s);
}

void MergeSort(string& s) {
    sortRange(0, s.size()-1, s);
}
