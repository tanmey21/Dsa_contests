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
  ll n,k;cin>>n>>k;
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i]; 

  vector<pair<ll,ll> > v(n);
  for(int i=0;i<n;i++)v[i]=make_pair(a[i],i);
  sort(v.begin(),v.end());
  
  priority_queue<ll,vector<ll>,greater<ll> > pq;
    ll dp[n];ll sm=0;
    for(int i=0;i<n;i++){
        if(i==0){
            dp[i]=0;
            pq.push(b[v[i].second]);
            sm+=b[v[i].second];
        }
        else{
            dp[i]=sm;ll curr=b[v[i].second];
            if(pq.size()<k){
                pq.push(b[v[i].second]);
                sm+=b[v[i].second];
            }
            else{
                ll mi=pq.top();
                if(mi<curr){
                    pq.pop();sm-=mi;
                    pq.push(curr);sm+=curr;
                }
            }
        }
    }

    vector<ll> fa(n);
    for(int i=0;i<n;i++){
        int idx=v[i].second;
        fa[idx]=dp[i];
    }
    for(auto it:fa)cout<<it<<" ";
    cout<<endl;

  }
}