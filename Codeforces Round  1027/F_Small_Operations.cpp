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

const int N=1e6+5;
vector<int> primes(N,-1);

void si(){
  for(int i=2;i<N;i++){
    if(primes[i]!=-1)continue;
    for(int j=1;i*j<N;j++){
      if(primes[i*j]==-1)primes[i*j]=i;
    }
  }
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);    
}

int solve(int v,int k){
  map<ll,ll> mp;
  vector<ll> f;
  for(int i=1;i*i<=v;i++){
    if(v%i==0){
      f.push_back(i);
      if(v/i != i)f.push_back(v/i);
    }
  }
  sort(f.begin(),f.end());
  int sz=f.size();
  for(int i=sz-1;i>=0;i--){
    ll val=f[i];ll fa=1e9;
    if(val!=v){
      for(int j=1;j<sz;j++){
        if(f[j]>k)continue;
        ll new_val=val*f[j];
        if(new_val>v)continue;
        if(v%new_val==0){
          ll ans=1+mp[new_val];
          fa=min(fa,ans);
        }
      }
      mp[val]=fa;
    }
    else mp[val]=0;
  }
  return mp[1];
}

int main() {
fastio();
int tc;cin>>tc;si();
while(tc--){
  ll x,y,k;cin>>x>>y>>k;
  if(x==y){
    cout<<0<<endl;continue;
  }
  int g=gcd(x,y);
  int v1=x/g;int v2=y/g;
  vector<int> p1;
  vector<int> p2;
  while(v1!=1){
    p1.push_back(primes[v1]);
    int t=primes[v1];
    v1/=t;
  }
  while(v2!=1){
    p2.push_back(primes[v2]);
    int t=primes[v2];
    v2/=t;
  }
  int i1=p1.size()-1;int i2=p2.size()-1;
  int great=-1;
  while(i1>=0 && i2>=0){  
    if(p1[i1]==p2[i2]){
      i1--;i2--;
    }
    else{
      great=max(p1[i1],p2[i2]);break;
    }
  }
  debug(p1);debug(p2);
  if(great==-1){
    if(i1>=0)great=p1[i1];
    else great=p2[i2];
  }
  debug(great);
  if(great>k){
    cout<<-1<<endl;continue;
  }
   v1=x/g; v2=y/g;
  ll fa=solve(v1,k)+solve(v2,k);
  cout<<fa<<endl;
  }
}