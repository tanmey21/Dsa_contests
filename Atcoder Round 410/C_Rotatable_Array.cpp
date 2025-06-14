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
   ll n,q;cin>>n>>q;
   vector<ll> a(n);
   for(int i=0;i<n;i++)a[i]=i+1;
   ll total=0;
   while(q--){
    ll x;cin>>x;
    if(x==1){
        ll idx,val;cin>>idx>>val;idx--;
        ll fidx=(idx+total)%n;
        a[fidx]=val;
    }
    else if(x==2){
        ll idx;cin>>idx;idx--;
        ll fidx=(idx+total)%n;
        cout<<a[fidx]<<endl;
    }
    else{
        ll k;cin>>k;
        total+=k;
    }
   }
  }
}