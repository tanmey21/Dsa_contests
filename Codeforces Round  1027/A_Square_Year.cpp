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
  string s;cin>>s;
  int x=0;
  for(int i=0;i<4;i++){
    x*=10;x+=(s[i]-'0');
  }
  int fa=sqrt(x);
  if(fa*fa!=x){
    cout<<-1<<endl;
  }
  else{
    cout<<0<<" "<<fa<<endl;
  }
  }
}