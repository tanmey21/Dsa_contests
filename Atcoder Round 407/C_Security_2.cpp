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

const int N=1e9;

int main() {
fastio();
int tc=1;
while(tc--){
   string a;cin>>a;
   int n=a.size();
   int fa=0;
   int sm=0;
   for(int i=n-1;i>=0;i--){
        int v=(a[i]-'0'-sm+N)%10;
        sm+=v;
        fa+=v;
   }
   fa+=n;
   cout<<fa<<endl;
  }
}