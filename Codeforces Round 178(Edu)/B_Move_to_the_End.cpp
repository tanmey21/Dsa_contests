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
  
  vector<ll> suff(n);
  for(int i=n-1;i>=0;i--){
    if(i==n-1)suff[i]=a[i];
    else suff[i]=suff[i+1]+a[i];
  }
  multiset<int> ms;
  for(int i=0;i<n-1;i++)ms.insert(a[i]);
  for(int i=1;i<=n;i++){
    int idx=n-i;
    if(i==n){
        cout<<suff[0]<<" ";
        cout<<endl;continue;
    }
    auto it=(--ms.end());
    ll fa;
    if(*it>a[idx]){
        fa=suff[idx]-a[idx]+*it;
    }
    else fa=suff[idx];
    cout<<fa<<" ";
    debug(idx);
    auto it2=ms.find(a[idx-1]);
    ms.erase(it2);
    debug(ms);
  }
  }
}