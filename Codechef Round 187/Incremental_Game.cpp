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
  int x,y;cin>>x>>y; int k;cin>>k;
  int f=0;
  if(x>=k){
    int v=x-k;
    if(v<=k && y<=k)f=1;
  }
  else{
    if(y<=k)f=1;
  }

  if(y>=k){
    int v=y-k;
    if(x<=k && v<=k)f=1;
  }
  else{
    if(x<=k)f=1;
  }
  if(f)cout<<"Alice"<<endl;
  else cout<<"Bob"<<endl;
  
  }
}