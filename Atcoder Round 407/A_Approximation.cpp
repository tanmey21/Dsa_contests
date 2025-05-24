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
  int a,b;cin>>a>>b;
  int v=a/b;
  int v1=v*b;int v2=(v+1)*b;
  
  
  if(a-v1 > v2-a)cout<<v+1<<endl;
  else cout<<v<<endl;
  }
}