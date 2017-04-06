#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
ll modpow(ll x, ll y, ll mod) {
    ll ret = 1;
    while(y) {
        if(y&1)
            ret = modmultiply(ret, x, mod);
        x = modmultiply(x, x, mod);
        y >>= 1;
    }
    return ret;
}

int isprime(ll n) {
    if(n == 2 || n == 3)
        return 1; 
    if(n < 2 || (n&1) == 0)    
        return 0;
    int a;
    for(int i = 0; i < 5; i++) {
        a = rand()%(n-4)+2; // Remember to call srand(time(NULL)) !
        if(modpow(a, n-1, n) != 1)
            return 0;
    }
    return 1;
}
