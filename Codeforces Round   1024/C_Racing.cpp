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
  
  vector<pair<int,int> > v(n);
  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;

  vector<pair<int,int> > store;

  int s=0;int e=0;int flag=1;
  for(int i=0;i<n;i++){
    if(a[i]==-1)e++;
    else if(a[i]==1){
        s++;e++;
    }
    if(v[i].second<s || v[i].first>e)flag=0;
    else{
        s=max(s,v[i].first);
        e=min(e,v[i].second);
    }

    store.push_back(make_pair(s,e));
  }

  debug(store);

  if(!flag)cout<<-1<<endl;
  else{
    vector<int> tmp(n);
    vector<int> all;
    vector<int> fa(n);
    for(int i=0;i<n;i++){debug(i);
        if(a[i]==-1)all.push_back(i);
        s=store[i].first; e=store[i].second;
       
            int prev;
            if(i==0)prev=0;
            else prev=fa[i-1];

            int ans=prev;
            if(a[i]==0){
                ans=max(ans,s);
                int d=ans-prev;
                while(d!=0){
                    int idx=all.back();
                    tmp[idx]=1;d--;
                    all.pop_back();
                }
                // if(d>=1){
                //     tmp[i-1]+=d;
                // }
                fa[i]=ans;
            }
            else if(a[i]==1){
                ans++;
                ans=max(ans,s);
                int d=ans-prev;
                while(d>1){
                    int idx=all.back();
                    tmp[idx]=1;d--;
                    all.pop_back();
                }
                fa[i]=ans;
            }
            else{
                debug(all);
                ans=max(ans,s);int d=ans-prev;
                while(d>=1){
                    int idx=all.back();
                    tmp[idx]=1;d--;
                    all.pop_back();
                }
                fa[i]=ans;
            }
        debug(fa);
    }

    debug(fa);

//     int sm=0;
//     for(int i=n-1;i>=0;i--){
//         sm+=tmp[i];
//         fa[i]+=sm;
//     }
//    vector<int> t(n);
//    for(int i=1;i<n;i++)t[i]=fa[i]-fa[i-1];
//    for(auto it:t)cout<<it<<" ";
//    cout<<endl;
    for(int i=0;i<n;i++){
        if(a[i]!=-1)tmp[i]=a[i];
    }
    for(auto it:tmp)cout<<it<<" ";
    cout<<endl;
  }
  }
}