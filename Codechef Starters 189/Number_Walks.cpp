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
  int n,k;cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];

  vector<vector<ll> > t(k+1);
  for(int i=1;i<=n;i++){
    int val=a[i-1];
    t[val].push_back(i);
  }
  debug(t);
  vector<ll> fa(n+1);
  vector<map<ll,ll> > v2(k+1);
  for(int i=k;i>=1;i--){map<ll,ll> mp;
    if(i==k){
        for(auto it:t[i])mp[it]=0;
        v2[i]=mp;
    }
    else{auto nxt=v2[i+1];
        for(auto it:t[i]){ll val1=1e18;ll val2=1e18;
            auto it1=nxt.lower_bound(it);
            if(it1!=nxt.end()){
                val1=(abs(it-it1->first))+it1->second;
            }
            if(it1!=nxt.begin()){
                --it1;
                val2=abs(it-it1->first)+it1->second;
            }
            mp[it]=min(val1,val2);
        }
        v2[i]=mp;
    }
  }
  auto nxt=v2[1];
  for(int i=1;i<=n;i++){
    ll val1=1e18;ll val2=1e18;
    auto it1=nxt.lower_bound(i);
    if(it1!=nxt.end()){
        val1=(abs(i-it1->first))+it1->second;
    }
    if(it1!=nxt.begin()){
        --it1;
        val2=abs(i-it1->first)+it1->second;
    }
    fa[i]=min(val1,val2);
  }
  for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
  cout<<endl;
  }
}