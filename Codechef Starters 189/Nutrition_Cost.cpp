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
   int n,c;cin>>n>>c;
   vector<ll> a(n);
   for(int i=0;i<n;i++)cin>>a[i];
   vector<ll> b(n);
   for(int i=0;i<n;i++)cin>>b[i];

   vector<pair<ll,ll> > v(n);
   for(int i=0;i<n;i++)v[i]=make_pair(b[i],a[i]);

   debug(v);

    sort(v.begin(),v.end());
    ll fa=0;ll sm=0;
    set<int> done;
    for(int i=0;i<n;i++){
        if(done.count(v[i].second))continue;
        sm+=(c-v[i].first);
        fa=max(fa,sm);
        done.insert(v[i].second);
    }
    cout<<fa<<endl;
  }
}