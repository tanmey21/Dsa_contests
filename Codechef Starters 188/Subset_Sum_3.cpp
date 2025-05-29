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
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  for(auto &it:a)it%=3;

  int f=0;
  for(auto it:a){
    if(it==0)f=1;
  }
  // 1 and 2 or 1 1 1 or 2 2 2
  map<int,int> mp;
  for(auto it:a)mp[it]++;
  if(mp.count(1) && mp.count(2))f=1;
  else if(mp[1]>=3)f=1;
  else if(mp[2]>=3)f=1;
  if(f)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  }
}