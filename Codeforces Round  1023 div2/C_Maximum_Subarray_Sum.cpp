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

const ll val=-1e17;

ll maxSubarraySum(vector<ll>& nums) {
    ll maxSoFar = nums[0];
    ll currentMax = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        currentMax = max(nums[i], currentMax + nums[i]);
        maxSoFar = max(maxSoFar, currentMax);
    }

    return maxSoFar;
}

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  ll n,k;cin>>n>>k;
  string s;cin>>s;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];

  int flag=1;
  for(auto it:s){
    if(it=='0')flag=0;
  }
  if(flag){
    ll sm=maxSubarraySum(a);
    if(sm==k){
        cout<<"Yes"<<endl;
        for(auto it:a)cout<<it<<" ";
        cout<<endl;
    }
    else cout<<"No"<<endl;

    continue;
  }
  ll tmp=0;
  for(int i=0;i<n;){
    if(s[i]=='1'){
        int idx=i;
        for(int j=i;j<n;j++){
            if(s[j]=='0')break;
            idx=j;
        }   
        vector<ll> b;
        for(int j=i;j<=idx;j++)b.push_back(a[j]);
        ll sm=maxSubarraySum(b);
        tmp=max(tmp,sm);
        i=idx+1;
    }
    else i++;
  }
  if(tmp>k){
    cout<<"No"<<endl;continue;
  }
  cout<<"Yes"<<endl;
  vector<ll> fa(n);int f=0;int idx=-1;
  for(int i=0;i<n-1;i++){
    if(s[i]=='0' && s[i]==s[i+1]){idx=i;
        f=1;break;
    }
  }

  if(f){
    for(int i=0;i<n;i++){
        if(s[i]=='1')fa[i]=a[i];
        else{
            if(i==idx){
                ll sm=0;ll sm1=0;
                for(int j=i-1;j>=0;j--){
                    if(s[j]=='0')break;
                    else{ sm+=a[j];sm1=max(sm1,sm);}
                }
                ll more=k-sm1;
                fa[i]=more;
            }
            else fa[i]=val;
        }
    }
    for(auto it:fa)cout<<it<<" ";
    cout<<endl;
  }
  else{f=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){fa[i]=a[i];}
        else if(f)fa[i]=val;
        else{
           ll sm1=0;ll sm2=0;ll sm=0;
           for(int j=i-1;j>=0;j--){
            sm+=a[j];sm1=max(sm,sm1);
           }
           sm=0;
           for(int j=i+1;j<n;j++){
            if(s[j]=='0')break;
            sm+=a[j];
            sm2=max(sm2,sm);
           }
           if(sm1>=0 && sm2>=0){
            ll t=sm1+sm2;
            ll more=k-t;
            fa[i]=more;
           }
           else{
            ll t=max(sm1,sm2);
            ll more=k-t;
            fa[i]=more;
           }
           f=1;
        }
    }
    for(auto it:fa)cout<<it<<" ";
    cout<<endl;
  }
  
  }
}