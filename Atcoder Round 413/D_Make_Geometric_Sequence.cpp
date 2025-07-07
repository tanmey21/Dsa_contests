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

ll Check(vector<ll> &a){
    ll f=1; ll n=a.size();
    for(ll i=1; i<n; i++){
        if(a[i] != a[i-1]) return 0;
    }
    return 1;
}

ll Check2(vector<ll> &a){
    ll f=1; ll n=a.size();
    for(ll i=1; i<n; i++){
        if(abs(a[i]) != abs(a[i-1])) return 0;
    }
    return 1;
}

void sortByAbsoluteValue(vector<ll>& arr) {
    sort(arr.begin(), arr.end(), [](ll a, ll b) {
        return abs(a) < abs(b);
    });
}

int main() {
    fastio();
    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];

        if(Check(a)){
            cout << "Yes" << endl;
            continue;
        }

        sort(a.begin(), a.end());

        if(a[0] * a.back() > 0){
            ll f = 1;
            for(ll i=1; i<=n-2; i++){
                if(a[i]*a[i] != a[i-1]*a[i+1]) f = 0;
            }
            if(f) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            sortByAbsoluteValue(a);
            if(Check2(a)){
                int c1=0;int c2=0;
                for(auto it:a){
                    if(it>0)c1++;
                    else c2++;
                }
                if(abs(c1-c2)<=1)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;

                continue;
            }
            ll f = 1;
            for(ll i=1; i<=n-2; i++){
                if(a[i]*a[i] != a[i-1]*a[i+1]) f = 0;
            }
            if(f) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
