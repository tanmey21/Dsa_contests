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

const int N=2e5+5;
vector<pair<ll,ll> > t(N);

void dfs(int curr,int par,vector<int> adj[],vector<ll> &a){
    if(par==-1){
        t[curr]=make_pair(a[curr-1],0);
    }
    else{
        auto it=t[par];
        ll mx=a[curr-1]-it.second;
        ll mi=a[curr-1]-it.first;

        mi=min((ll)0,mi);
        t[curr]=make_pair(mx,mi);
    }
    for(auto it:adj[curr]){
        if(it==par)continue;
        dfs(it,curr,adj,a);
    }
}

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n;cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  vector<int> adj[n+1];
  for(int i=0;i<n-1;i++){
    int x,y;cin>>x>>y;adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(1,-1,adj,a);
  for(int i=1;i<=n;i++){
    cout<<t[i].first<<" ";
  }
//   debug(t);
  cout<<endl;

  }
}