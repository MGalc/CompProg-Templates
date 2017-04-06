#include <bits/stdc++.h>
using namespace std;

vector<int> primes; // Global variable to store our primes
static const int maxFactor = 1e9; // The maximum number to support factorisation for.
void genPrimes() {
    primes.clear();
    primes.push_back(2);
    vector<bool> isprime(sqrt(maxFactor)+1, true);
    for (int i = 3; i <= sqrt(maxFactor); i++) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i+i; j < isprime.size(); j+=i) {
            isprime[j] = false;
        }
    }
}
