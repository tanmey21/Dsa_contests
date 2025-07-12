#include "bits/stdc++.h"
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD2 1000000007
#define MOD1 998244353
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

const int N=2e5+5;

vector<ll> fac(N), inv_fac(N);

// Function to precompute factorials and their modular inverses

unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1;
    x = x % p; 
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void precomputeFactorials(ll mod){
    fac[0] = 1;
    for(int i = 1; i < N; i++){
        fac[i] = (fac[i-1] * i) % mod;
    }
    // Precompute modular inverses using Fermat’s little theorem
    inv_fac[N-1] = power(fac[N-1], mod - 2, mod);
    for(int i = N - 2; i >= 0; i--){
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
    }
}

// Function to calculate power with modular exponentiation


// Function to calculate nCr % p using precomputed factorials and inverses
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    return (fac[n] * inv_fac[r] % p * inv_fac[n - r] % p) % p;
}

int64_t fastFloorSum(int64_t n) {
    int64_t res = 0;
    int64_t i = 2;
    while (i <= n) {
        int64_t val = n / i;
        int64_t j = n / val;
        j = min(j, n);

        int64_t start = max(i, int64_t(2)); // skip i = 1
        if (j >= start) {
            int64_t count = (j - start + 1) % MOD1;
            res = (res + (count * (val % MOD1)) % MOD1) % MOD1;
        }
        i = j + 1;
    }
    return res;
}
int main() {
fastio();
int tc=1;precomputeFactorials(MOD1);
while(tc--){
   ll n;cin>>n;
   ll sm1 = ((n%MOD1)*((n-1)%MOD1))%MOD1;

   ll sm2 = ((n%MOD1)*((n+1)%MOD1));

   sm2%=MOD1;
   sm2*=inv_fac[2];
   sm2%=MOD1;
   sm2-=1;sm2+=MOD1;sm2%=MOD1;


   ll sm3 = (n-1)%MOD1;
  
   ll fa1=(sm1-sm2+sm3+(10ll)*MOD1)%MOD1;
  

   ll fa2 = fastFloorSum(n);

   ll fa=(fa1-fa2+MOD1)%MOD1;
   cout<<fa<<endl;
  }
}