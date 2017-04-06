#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b) {
    return !b ? a : gcd(b, a % b); 
}

ll modmultiply(ll a,ll b,ll c) {
    ll x = 0,y = a%c; 
    while(b > 0) {
        if(b%2 == 1) {
            x = (x+y)%c; 
        }
        y = (y*2)%c;
        b /= 2; 
    }
    return x%c; 
}

ll pollard_rho(ll n, ll c) {
    ll x = 2, y = 2;
    do {
        x = (modmultiply(x, x, n)+c)%n;
        y = (modmultiply(y, y, n)+c)%n;
        y = (modmultiply(y, y, n)+c)%n;
        ll d = gcd(x-y, n);
        if(d > 1)    return d;
    } while(true);
    return n;
}

// This is the function to call if wanting a factor of a number.
// n is the value to get a factor for.
// To use:
// factor1 = getFactors(n);
// factor2 = n / a;
ll getFactors(int n) {
    ll p1 = n;
    for(int c = 2; p1 == n; c++) {
        p1 = pollard_rho(n, c);
    }
    return p1;
}
