#include "bits/stdc++.h"
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
typedef long long ll;

#define pp pair<ll,ll>

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
  ll n,m;cin>>n>>m;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  vector<pair<ll,ll> > adj[n+1];
  ll mx=0;ll mi=1e9;
  for(int i=0;i<m;i++){
    ll x,y,z;cin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z));
    mx=max(mx,z);
    mi=min(mi,z);
  }

  ll s=mi;ll e=mx;ll fa=-1;
  while(s<=e){
    ll mid=(s+e)/2;

    // mid=10;
    vector<ll> t(n+1,-1);
    t[1]=a[0];

    vector<ll> dp(n+1,-1);
    dp[1]=a[0];

    for(int i=1;i<=n;i++){
        for(auto it:adj[i]){
            if(it.second>mid)continue;
            if(dp[i]>=it.second){
                dp[it.first]=max(dp[it.first],dp[i]+a[it.first-1]);
            }
        }
    }
    debug(t);
    if(dp[n]!=-1){
        fa=mid;e=mid-1;
    }
    else s=mid+1;

    // break;
  }
 
cout<<fa<<endl;
  }
}