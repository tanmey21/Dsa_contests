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
  int x,y;cin>>x>>y;
  int c=0;
  for(int i=1;i<=6;i++){
    for(int j=1;j<=6;j++){
      if(i+j>=x || abs(i-j)>=y){
        c++;
      }
    }
  } 
  double ans = (double)c / 36.0; // Total outcomes are 6*6 = 36
  //in answer increase the precision to 10 decimal places
    cout << fixed << setprecision(10) << ans << endl;
  }
}