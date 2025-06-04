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

  ll fa=0;
  
  for(int i=0;i<n;i++){
    vector<int> t;
    for(int j=i;j<n;j++){t.push_back(a[j]);
        // debug(t);
    ll p=-1;int flag=1;
    for(auto it:t){
        ll need=p+1;
        if(need==0){p=0;
            continue;
        }
        else{
            //it%x == need
            //mi (need+1)+need
            ll need=p+1;
            ll mi=(need+1)+need;
            if(it>=mi){
                p++;continue;
            }
            else if(it<=p){
                flag=0;break;
            }
            else{
                p=it;
            }
        }
    }
    if(flag)fa++;
    }
  }
  cout<<fa<<endl;
  }
}