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
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  } 
  int k;cin>>k;
  int c=0;
  for(auto it:a){
    if(it>=k)c++;
  }
  cout<<c<<endl;
  }
}