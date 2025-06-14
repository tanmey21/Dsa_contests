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
int tc=1;
while(tc--){
  int n,m;cin>>n>>m;
  vector<pair<int,int> > adj[n+1];
  for(int i=0;i<m;i++){
    int x,y,z;cin>>x>>y>>z;
    adj[x].push_back(make_pair(y,z));
  } 
  int dp[n+1][2001];
  memset(dp,-1,sizeof(dp));
  dp[1][0]=1;
  queue<pair<int,int> > q;
  q.push(make_pair(1,0));
  while(!q.empty()){
    auto f=q.front();q.pop();
    int node=f.first;int prev=f.second;
    for(auto it:adj[node]){
        int w=it.second;int node2=it.first;
        int val=w^prev;
        if(dp[node2][val]==-1){
            dp[node2][val]=1;
            q.push(make_pair(node2,val));
        }
    }
  }
  int fa=-1;
  for(int i=0;i<=2000;i++){
    if(dp[n][i]!=-1){
        fa=i;break;
    }
  }
  cout<<fa<<endl;
  }
}