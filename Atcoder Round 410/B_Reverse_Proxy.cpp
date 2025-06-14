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
  int n,q;cin>>n>>q;
  vector<int> a(q);
  for(int i=0;i<q;i++)cin>>a[i]; 

  vector<int> count(n+1);

  vector<int> fa;
  
  for(auto it:a){
    if(it>=1){
        count[it]++;
        fa.push_back(it);
    }
    else{
        int idx=1;int mi=count[idx];
        for(int i=2;i<=n;i++){
            if(count[i]<mi){
                mi=count[i];
                idx=i;
            }
        }
        count[idx]++;
        fa.push_back(idx);
    }
  }
for(auto it:fa)cout<<it<<" ";
cout<<endl;
  }
}