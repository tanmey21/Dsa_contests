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
   ll n,h,m;cin>>n>>h>>m;
   vector<pair<ll,ll> > a(n);
   for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;

 int dp[n][3000+1];int fa=0;
 memset(dp,-1,sizeof(dp));
 for(int i=0;i<n;i++){
    // cout<<i<<endl;
    for(int j=0;j<=h;j++){
        if(i==0){
            if(j==h)dp[i][j]=m-a[i].second;
            else if(j==h-a[i].first && j>=0)dp[i][j]=m;
            else dp[i][j]=-1;
        }
        else{
            int v1=j+a[i].first;
            // if(i==1 && j==0)cout<<v1<<endl;
            int mx=-1;
            if(v1<=h && dp[i-1][v1]>=0){
                mx=max(mx,dp[i-1][v1]);
            }
            if(dp[i-1][j]>=0){
                int v2=dp[i-1][j]-a[i].second;
                if(v2>=0)mx=max(mx,v2);
            }
            dp[i][j]=mx;
        }
    }
    int flag=0;
    for(int j=0;j<=h;j++){
        if(dp[i][j]>=0){flag=1;break;}
    }
    if(flag){
        fa=i+1;
    }
    else break;
 }

 cout<<fa<<endl;
  }
}