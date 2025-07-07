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

int Check(vector<ll> &a){int n=a.size();
    for(int i=1;i<n;i++){   
        if(a[i]%a[i-1]!=0)return 0;
    }   
    return 1;
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);    
}

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n;cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  if(Check(a)){
    cout<<1<<endl;continue;
  }
  ll mi=1;
  for(int i=1;i<n;i++){
    if(a[i]%a[i-1]!=0){
        ll g=gcd(a[i-1],a[i]);
        ll mi2=a[i-1];
        g=mi2/g;
        if(mi%g==0){
            continue;
        }
        else{
            ll g2=gcd(mi,g);
            g/=g2;
            mi*=g;
        }
    }
  }
  cout<<mi<<endl;
  
  }
}