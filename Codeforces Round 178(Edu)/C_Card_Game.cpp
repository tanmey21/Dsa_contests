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
  int n;cin>>n;string a;cin>>a;
  if(n==2){
    if(a[0]=='A')cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    continue;
  }
  if(a[0]==a.back()){
    if(a[0]=='A')cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    continue;
  }
  if(a[0]=='B'){
        if(a[n-2]=='B'){
            cout<<"Bob"<<endl;
        }
        else cout<<"Alice"<<endl;
  }
  else{
    int c=0;
    for(auto it:a){
        if(it=='B')c++;
    }
    if(c>=2){
        cout<<"Bob"<<endl;
    }
    else cout<<"Alice"<<endl;
  }
  }
}