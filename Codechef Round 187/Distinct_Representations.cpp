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
  int n;cin>>n;
  string a;cin>>a;
  ll dp[n];
  vector<int> v(n);
  for(int i=0;i<n;i++){
    if(i==0)v[i]=i;
    else if(a[i]!=a[i-1])v[i]=v[i-1];
    else v[i]=i;
  }

  for(int i=0;i<n;i++){
    if(i<=2)dp[i]=1;
    else{
        int idx=v[i];
        int len=i-idx+1;
        if(len<=3){
            dp[i]=dp[i-1];
        }
        else{
            ll fa=0;
            fa+=dp[i-3];
            fa+=dp[i-1];
            fa%=MOD1;
            dp[i]=fa;
        }
    }
  }
  cout<<dp[n-1]<<endl;
  }
}