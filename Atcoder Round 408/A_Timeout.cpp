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
  int n;cin>>n;int s;cin>>s;
  vector<int> a(n);

  int f=1;int p=0;
  for(int i=0;i<n;i++)cin>>a[i]; 
  for(int i=0;i<n;i++){
    int d=a[i]-p;
    if(d>=s+.5)f=0;
    p=a[i];
  }
  if(f)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  }
}