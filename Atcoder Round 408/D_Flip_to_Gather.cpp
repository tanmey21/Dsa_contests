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

  vector<pair<int,int> > v;
  int fa=0;int mx=0;
  for(int i=0;i<n;){
    if(a[i]=='0'){
      i++;
    }
    else{
      int s=i;int fidx=i;
      for(int j=i+1;j<n;j++){
        if(a[j]=='1')fidx=j;
        else break;
      }
      fa+=(fidx-i+1);
      mx=max(mx,fidx-i+1);
      v.push_back(make_pair(i,fidx));
      i=fidx+1;
    }
  }
  fa-=mx;
if(v.size()==1 || v.size()==0){
  cout<<0<<endl;continue;
}
int sz=v.size();
vector<int> pre0(n);
vector<int> pre1(n);
vector<int> suff0(n);
vector<int> suff1(n);
for(int i=0;i<n;i++){
  if(i==0){
    if(a[i]=='0')pre0[i]=1;
  }
  else{
    if(a[i]=='0')pre0[i]=pre0[i-1]+1;
    else pre0[i]=pre0[i-1];
  }
}

for(int i=0;i<n;i++){
  if(i==0){
    if(a[i]=='1')pre1[i]=1;
  }
  else{
    if(a[i]=='1')pre1[i]=pre1[i-1]+1;
    else pre1[i]=pre1[i-1];
  }
}

for(int i=n-1;i>=0;i--){
  if(i==n-1){
    if(a[i]=='0')suff0[i]=1;
  }
  else{
    if(a[i]=='0')suff0[i]=suff0[i+1]+1;
    else suff0[i]=suff0[i+1];
  }
}

for(int i=n-1;i>=0;i--){
  if(i==n-1){
    if(a[i]=='1')suff1[i]=1;
  }
  else{
    if(a[i]=='1')suff1[i]=suff1[i+1]+1;
    else suff1[i]=suff1[i+1];
  }
}

vector<int> t1(sz);
vector<int> t2(sz);
for(int i=0;i<sz;i++){
  int idx1=v[i].first;int idx2=v[i].second;
  int c1=0;int c2=0;
  if(idx1!=0)c1=pre1[idx1-1];
  if(idx1!=0)c2=pre0[idx1-1];

  t1[i]=c1-c2;
}
for(int i=0;i<sz;i++){
  int idx1=v[i].first;int idx2=v[i].second;
  int c1=0;int c2=0;
  if(idx2!=n-1)c1+=suff1[idx2+1];
  if(idx1!=0)c2+=pre0[idx1-1];
  t2[i]=c1+c2;
}
for(int i=sz-2;i>=0;i--){
  t2[i]=min(t2[i],t2[i+1]);
}

for(int i=0;i<sz-1;i++){
  int ans=t1[i]+t2[i+1];
  fa=min(fa,ans);
}
cout<<fa<<endl;


  }
}