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
  int q;cin>>q;
  deque<pair<ll,ll> > qu;
  while(q--){
    int x;cin>>x;
    if(x==1){ll c,val;cin>>c>>val;
        qu.push_back(make_pair(c,val));
    }
    else{
        ll sm=0;
        ll k;cin>>k;
        while(k!=0){
            auto front = qu.front();qu.pop_front();
            if(k>=front.first){
                k-=front.first;
                sm+=(front.first*front.second);
            }
            else{
               
                sm+=(front.second*k);
                ll left = front.first-k;
                k=0;
                qu.push_front(make_pair(left,front.second));
            }
        }
        cout<<sm<<endl;
    }
  } 
  }
}