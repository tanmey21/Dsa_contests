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
  vector<pair<int,int> > a(m);
  for(int i=0;i<m;i++)cin>>a[i].first>>a[i].second;
  vector<int> t(n+1);
  for(auto it:a){
    int l=it.first;int r=it.second;
    t[r]++;
    t[l-1]--;
  }

  for(int i=n-1;i>=0;i--){
    t[i]+=t[i+1];
  }
  int fa=m;
  for(int i=1;i<=n;i++){
    fa=min(fa,t[i]);
  }
  cout<<fa<<endl;

  }
}