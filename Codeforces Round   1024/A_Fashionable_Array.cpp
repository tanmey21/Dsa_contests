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
  
  sort(a.begin(),a.end());
  int sm=a[0]+a.back();
  if(sm%2==0){
    cout<<0<<endl;
  }
  else{
    int fidx=0;int fidx2=n-1;
    for(int j=1;j<n;j++){
        if(a[0]%2 != a[j]%2){fidx=j;break;}
    }
    for(int j=n-2;j>=0;j--){
        if(a[n-1]%2 != a[j]%2){
            fidx2=j;break;
        }
    }
    int d1=fidx-1+1;
    int d2=n-1-(fidx2+1)+1;
    cout<<min(d1,d2)<<endl;
  }
  }
}