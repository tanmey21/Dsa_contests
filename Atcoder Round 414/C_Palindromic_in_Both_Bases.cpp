#include "bits/stdc++.h"
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

const ll N = 1e6 + 1;

ll helper(ll n, ll a){
    vector<ll> dig;
    while(n){
        dig.push_back(n % a);
        n /= a;
    }
    ll s = 0, e = dig.size() - 1;
    while(s < e){
        if(dig[s] != dig[e]) return 0;
        s++; e--;
    }
    return 1;
}

int main() {
    fastio();
    ll tc = 1;
    while(tc--){
        ll a, n;
        cin >> a >> n;
        ll fa = 0;
        for(ll i = 1; i < N; i++){
            ll t = i;
            vector<ll> dig;
            while(t != 0){
                dig.push_back(t % 10);
                t /= 10;
            }
            reverse(dig.begin(), dig.end());
            vector<ll> d1 = dig;
            vector<ll> d2 = dig;
            reverse(dig.begin(),dig.end());
            for(auto it : dig) d1.push_back(it);
            ll sz = dig.size();
            for(ll j = 1; j < sz; j++){
                d2.push_back(dig[j]);
            }
            ll n1 = 0, n2 = 0;
            for(auto it : d1){
                n1 *= 10;
                n1 += it;
            }
            for(auto it : d2){
                n2 *= 10;
                n2 += it;
            }

            if(n1>0 && n1 <= n){
                if(helper(n1, a)){
                    fa += n1;
                }
            }
            if(n2>0 && n2 <= n){
                if(helper(n2, a)){
                    fa += n2;
                }
            }
        }
        cout << fa << endl;
    }
}
