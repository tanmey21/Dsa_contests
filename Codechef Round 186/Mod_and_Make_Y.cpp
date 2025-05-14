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

const int N=5e4+5;

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n,x,y;cin>>n>>x>>y;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  vector<int> fa;
  int fidx=-1;
  for(int i=0;i<n;i++){
    if(a[i]<=y)break;
    else fidx=i;
  }
  int s=0;int e=fidx;int ans=-1;
  if(x==y){
    cout<<fidx+1<<endl;
    for(int i=0;i<fidx+1;i++)cout<<i+1<<" ";
    cout<<endl;
    continue;
  }
  while(s<=e){
    int mid=(s+e)/2;
    int dp[x+1];
    memset(dp,0,sizeof(dp));
    dp[x]=1;
    for(int i=x;i>=0;i--){
        if(dp[i]){
            for(int j=0;j<=mid;j++){
                int val=i%a[j];
                dp[val]=1;
            }
        }
    }
    if(dp[y]){
        ans=mid;e=mid-1;
    }
    else s=mid+1;
  }
  debug(ans);
  if(ans==-1){
    cout<<0<<endl;
  }
  else{
    cout<<fidx-ans+1<<endl;
    for(int i=ans;i<=fidx;i++)cout<<i+1<<" ";
    cout<<endl;
  }
  }
}