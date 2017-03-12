#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

vii matrixMult(const vii& m1, const vii& m2) {
    if (m2.size() != 0 && m1.size() != m2[0].size()) 
        throw length_error("Matrices cannot be multiplied");
    vii answer(m1.size(), vi(m2[0].size(), 0));
    for (int i = 0; i < m1.size(); i++) { // row
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m2.size(); k++) { // loop over rows of m2
                answer[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return answer;
}

vii matrixPow(vii& base, int pow) {
    if (base.size() != 0 && base.size() != base[0].size()) 
        throw invalid_argument("base is not a square matrix");
    vii answer(base.size(), vi(base[0].size(), 0));
    for (int i = 0; i < min(answer.size(), answer[0].size()); i++)
        answer[i][i] = 1; // Create identity matrix

    while (pow > 0) {
        if (pow & 1) {
            answer = matrixMult(answer, base);
        }
        base = matrixMult(base, base);
        pow >>= 1;
    }

    return answer;
}
