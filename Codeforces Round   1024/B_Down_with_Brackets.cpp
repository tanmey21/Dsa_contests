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

bool isBalanced(string a){
    int n=a.size();
    int f=1;int c=0;
    for(int i=0;i<n;i++){
        if(a[i]=='(')c++;
        else c--;
        if(c<0)return 0;
    }   
    return 1;
}

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  string a;cin>>a;
  int n=a.size();
  
    int idx1=-1;int idx2=-1;
    for(int i=0;i<n;i++){
        if(a[i]==')')idx2=i;
        if(a[i]=='(' && idx1==-1)idx1=i;
    }

    string b;
    for(int i=0;i<n;i++){
        if(i==idx1 || i==idx2)continue;
        else b+=a[i];
    }

    debug(b);

    if(isBalanced(b))cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

  }
}