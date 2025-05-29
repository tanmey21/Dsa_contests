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
  ll n;cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];

  sort(a.begin(),a.end());
  
   int fa=1e9;
   for(int i=0;i<=n;i++){
    auto it=lower_bound(a.begin(),a.end(),i+1);
    int c=0;
    if(it==a.end())c=0;
    else{
        int idx=it-a.begin();
        c=n-1-(idx)+1;
    }
    debug(i);debug(c);
    int ans=i+c;
    fa=min(fa,ans);
   }
   cout<<fa<<endl;
  
  }
}