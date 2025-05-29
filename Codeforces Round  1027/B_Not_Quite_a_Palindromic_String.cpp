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
  string a;cin>>a;
  
  int c1=0;int c2=0;
  for(auto it:a){
    if(it=='1')c1++;
    else c2++;
  }

  int f=1;
  while(1){
    if(k==0)break;
    if(c1>=c2){
        if(c1>1){
            c1-=2;k--;
        }
        else break;
    }
    else{
        if(c2>1){
            c2-=2;k--;
        }
        else break;
    }

    if(k==0)break;
  }
  if(k){
    cout<<"NO"<<endl;continue;
  }
  if(c1!=c2)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  }
}