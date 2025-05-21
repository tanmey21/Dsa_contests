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
  int n,x;cin>>n>>x;
  set<int> v;
  for(int i=1;i<=n;i++){
    int flag=1;
    for(int j=0;j<31;j++){
        int b1=0;int b2=0;
        if(x&(1<<j))b1=1;
        if(i&(1<<j))b2=1;
        if(!b1){
            if(b2)flag=0;
        }
    }
    if(flag)v.insert(i);
  }
  int mx=0;
  for(int j=0;j<31;j++){
    if(x&(1<<j))mx=j;
  }
  map<int,int> mp;
  if(x<=n){
    for(int i=n;i>=1;i--){
        if(!v.count(i))continue;
        if(i==x){
            mp[x]=x;continue;
        }
        int idx=0;
        for(int j=0;j<31;j++){
            if(i&(1<<j))idx=j;
        }
        if(idx==mx){debug(i);
            int val=0;
            for(int j=0;j<31;j++){
                int b1=0;int b2=0;
                if(i&(1<<j))b2=1;
                if(x&(1<<j))b1=1;

                if(b1==1 && b2==0){
                    val^=(1<<j);
                }
            }
            debug(val);
            mp[i]=val;
            mp[val]=i;
        }
    }
  }
  else{
    for(int i=n;i>=1;i--){
        if(!v.count(i))continue;
        int idx=0;
        for(int j=0;j<31;j++){
            if(i&(1<<j))idx=j;
        }
        if(idx==mx){
            int val=0;
            for(int j=0;j<31;j++){
                int b1=0;int b2=0;
                if(i&(1<<j))b2=1;
                if(x&(1<<j))b1=1;

                if(b1==1 && b2==0){
                    val^=(1<<j);
                }
            }
            mp[i]=val;
            mp[val]=i;
        }
    }
  }

  vector<int> fa(n+1);
  for(int i=1;i<=n;i++){
    if(mp.count(i))fa[i]=mp[i];
    else fa[i]=i;
  }
  for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
  cout<<endl;

  }
}