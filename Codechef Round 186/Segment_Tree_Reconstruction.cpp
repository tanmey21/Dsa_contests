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

const int N=(1<<21)+1;
vector<int> col(N);
int l=0;

void dfs(int curr,int lvl,int total){
    if(lvl==total){
       return;
    }
    int c1=2*curr+1;int c2=2*curr+2;
    if(col[curr]==1){
        col[c1]=1;
        col[c2]=1;
    }
    else{
        int h=lvl+1;
        int sz=(1<<(total-h+1))-1;
        debug(sz);
        if(sz<=l){
            l-=sz;
            col[c1]=1;
        }
        else col[c1]=0;
        col[c2]=0;
    }
     dfs(c1,lvl+1,total);
     dfs(c2,lvl+1,total);
}

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n,k;cin>>n>>k;
  l=k;
   if(k==((1<<(n+1))-1)){
    cout<<"Yes"<<endl;
    for(int i=0;i<(1<<n);i++)cout<<"1";
    cout<<endl;continue;
   }
   col[0]=0;
   dfs(0,0,n);
   if(l>0){
    cout<<"No"<<endl;
   }
   else{
    cout<<"Yes"<<endl;
    int prev=(1<<n)-1;
    int nxt=(1<<(n+1))-2;
    for(int x=prev;x<=nxt;x++){debug(x);
        cout<<col[x];
    }
    cout<<endl;
   }

  }

}