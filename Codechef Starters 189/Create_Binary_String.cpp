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
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d; 
  ll fa1=0;ll fa2=0;
  fa1=n*a;//means 0000
  fa2=n*b;//means 1111
  
  for(int i=0;i<n;i++){
    ll aage=n-i-1;
    ll sm=(i+1)*aage*d;
    sm+=(i+1)*b;
    sm+=(aage)*a;
    fa1=max(fa1,sm);
  }

  for(int i=0;i<n;i++){
    ll aage=n-i-1;
    ll sm=(i+1)*aage*c;
    sm+=(i+1)*a;
    sm+=(aage)*b;
    fa2=max(fa2,sm);
  }
  cout<<max(fa1,fa2)<<endl;

  }
}