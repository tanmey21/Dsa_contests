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
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
 sort(a.begin(),a.end());
    int mx=0;int mi=1e9;
    mx=max(a[n-2],a[n-1]-1);
    mi=a[0];
    if(mx-mi<=k){
        ll t=0;
        for(auto it:a)t+=it;
        if(t%2)cout<<"Tom"<<endl;
        else cout<<"Jerry"<<endl;
    }
    else cout<<"Jerry"<<endl;
  }
}