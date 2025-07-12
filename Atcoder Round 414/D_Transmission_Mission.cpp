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
  ll n,m;cin>>n>>m;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  sort(a.begin(),a.end());
  vector<ll> v;
  for(int i=1;i<n;i++){
    ll d=a[i]-a[i-1];
    v.push_back(d);
  }
  sort(v.begin(),v.end());
  ll fa=0;
  if(v.size()<=m-1){
    cout<<fa<<endl;
  }
  else{
    reverse(v.begin(),v.end());
    for(int i=m-1;i<v.size();i++)fa+=v[i];
    cout<<fa<<endl;
  }
  }
}