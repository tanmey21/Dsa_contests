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
  int n,k;cin>>n>>k;
  string a;cin>>a; 
  vector<vector<int> > v(26);
  for(int i=0;i<n;i++){
    int t=a[i]-'a';
    v[t].push_back(i);
  }
  ll dp[n][k];
  ll dp2[n];
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<k;j++){
        auto it=lower_bound(v[j].begin(),v[j].end(),i);
        if(it==v[j].end())dp[i][j]=1;
        else{
            int idx=*it;
            int ans=1;
            if(idx!=n-1){
                ans+=dp2[idx+1];
            }
            else ans++;
            dp[i][j]=ans;
        }
    }

    ll mi=1e9;
    for(auto it:dp[i])mi=min(mi,it);
    dp2[i]=mi;
  }
  int q;cin>>q;
  while(q--){
    string b;cin>>b;int idx=-1;
    for(auto it:b){
        auto it2=lower_bound(v[it-'a'].begin(),v[it-'a'].end(),idx+1);
        if(it2==v[it-'a'].end()){idx=1e9+5;break;}
        idx=*it2;
    }
    // debug(idx);
    if(idx==1e9+5){
        cout<<0<<endl;continue;
    }
    ll fa=1e9;idx++;
    if(idx>=n){fa=1;
        cout<<fa<<endl;
    }
    else{
        for(int i=0;i<k;i++)fa=min(fa,dp[idx][i]);
        cout<<fa<<endl;
    }
  }
  }
}