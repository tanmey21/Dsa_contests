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
  
    vector<pair<int,int> > b(n);
    for(int i=0;i<n;i++)b[i]=make_pair(a[i],i);
    sort(b.begin(),b.end());
    vector<int> fa(n);
    if(b[0].first==b.back().first){
        cout<<"No"<<endl;continue;
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<n-1;i++)fa[b[i].second]=1;
    fa[b[n-1].second]=2;
    for(auto it:fa)cout<<it<<" ";
    cout<<endl;
  }
}