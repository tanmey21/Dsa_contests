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
  int k,a,b,x,y;cin>>k>>a>>b>>x>>y;
    int fa=0;
    if(x<=y){
        int d=k-(a-1);
        if(d>=0){int c= ceil(1.0 *(d/(x*1.0)));
        fa+=c;
        k-=c*x;}
        d= k-(b-1);
        if(d>=0){
            int c= ceil(1.0 *(d/(y*1.0)));
            fa+=c;
        }
    }
    else{
        int d=k-(b-1);
        debug(d);
        if(d>=0){int c= ceil(1.0 *(d/(y*1.0)));
        fa+=c;
        k-=c*y;}
        debug(k);
        d= k-(a-1);
        debug(d);
        debug(x);
        if(d>=0){
            int c= ceil((d/(x*1.0)));
            debug(c);
            fa+=c;
        }
    }
    cout<<fa<<endl;
  }
}