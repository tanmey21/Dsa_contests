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

const int N=6e6;
vector<int> t(N,-1);
vector<int> primes;

void si(){
    for(int i=2;i<N;i++){
        if(t[i]!=-1)continue;
        primes.push_back(i);
        for(int j=2;i*j<N;j++){
            t[i*j]=0;
        }
    }
}

int main() {
fastio();
int tc;cin>>tc;si();
while(tc--){
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];

  sort(a.begin(),a.end());
  
  int s=0;int e=n;int fa;
  while(s<=e){
    int mid=(s+e)/2;
    ll sm=0;int idx=0;
    for(int i=mid;i<n;i++){
        sm+=(primes[idx]-a[i]);
        idx++;
    }
    if(sm<=0){
        fa=mid;e=mid-1;
    }
    else s=mid+1;
  }
  cout<<fa<<endl;
  
  }
}