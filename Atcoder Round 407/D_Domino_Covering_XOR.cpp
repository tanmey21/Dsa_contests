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

const int N=25;
ll fa=0;

vector<vector<ll> > A(N,vector<ll>(N));


void dfs(int x,int y,vector<vector<ll> > &a){
    int n=a.size();int m=a[0].size();
    if(x>=n || y>=m){ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!a[i][j])ans^=A[i][j];
            }
        }
        fa=max(fa,ans);return;
    }
   if(a[x][y]){
    if(y<m-1){
        dfs(x,y+1,a);
    }
    else if(y==m-1){
        dfs(x+1,0,a);
    }
   }
   else{
    if(y<m-1 && a[x][y+1]==0){
        a[x][y]=1;a[x][y+1]=1;
        dfs(x,y+1,a);
        a[x][y]=0;a[x][y+1]=0;
    }
    if(x<n-1 && a[x+1][y]==0){
        a[x][y]=1;a[x+1][y]=1;
        if(y<m-1)dfs(x,y+1,a);
        else dfs(x+1,0,a);

        a[x][y]=0;a[x+1][y]=0;
    }
    if(y<m-1)dfs(x,y+1,a);
    else dfs(x+1,0,a);
   }
}

int main() {
fastio();
int tc=1;
while(tc--){
  ll n,m;cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cin>>A[i][j];
  } 

  vector<vector<ll> > a(n,vector<ll>(m));
  dfs(0,0,a);
  cout<<fa<<endl;

  }
}