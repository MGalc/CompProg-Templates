#include <bits/stdc++.h>
using namespace std;

// Use our sieve of eratosthenes
vector<int> primes; // Global variable to store our primes
static const int maxFactor = 1e9;
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

// val is the value to factorise, factors is where the value's prime factors are stored.
void genSmallFactors(int val, vector<int>& factors) {
    for (int i = 0; i < primes.size(); i++) {
        if (val <= 1)
            return;
        while (val % primes[i] == 0) {
            val /= primes[i];
            factors.push_back(primes[i]);
        }
    }
    if (val >= 2)
        factors.push_back(val);
}

int main() {
    genPrimes(); // REMEMBER TO DO THIS

    vector<int> tester;
    genSmallFactors(123456, tester);
    for (int x : tester)
        cout << x << " ";
    cout << endl;
}
