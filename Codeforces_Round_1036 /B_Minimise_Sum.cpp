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

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n;cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
    ll a1=0;ll a2=0;
    ll mi=1e9;
    for(int i=0;i<n;i++){
        mi=min(mi,a[i]);
        a1+=mi;
    }
    a2=a[0]+a[1];
    ll a3=1e18;
    if(n>=3){
        a3 = a[0]+min(a[0],a[1]);
    }
    cout<<min(a1,min(a2,a3))<<endl;
  }
}