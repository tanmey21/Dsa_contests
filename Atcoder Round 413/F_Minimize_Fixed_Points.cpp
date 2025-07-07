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
const int N = 1e5+5;
vector<int> primes(N,-1);

void si(){
    for(int i=2;i<N;i++){
        if(primes[i]!=-1)continue;
        for(int j=1;i*j<N;j++){
            if(primes[i*j]==-1)primes[i*j]=i;
        }
    }
}
//to get number of different sets - count 1 in siz or siz.size()
//clear parent and siz after DSU is used

//Disjoint Set Union
const int mxN=1e5+5;
ll parent[mxN]; //map<ll,ll> parent;
ll siz[mxN];    //map<ll,ll> siz;
void make_set(ll v) {
    parent[v]=v; siz[v]=1;
}
ll find_set(ll v) {
    return (v==parent[v])?v:parent[v]=find_set(parent[v]);
}
void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if(siz[a]<siz[b]) swap(a,b);
    parent[b] = a;
    siz[a]+=siz[b]; 
    siz[b]=0; //siz.erase(b);
}
ll get_size(ll v){
    return siz[find_set(v)];
}
vector<int> helper(vector<int> a){
    int n=a.size();
    vector<int> fa;
    for(int i=1;i<n;i++)fa.push_back(a[i]);
    fa.push_back(a[0]);
    return fa;
}
int main() {
fastio();
int tc;cin>>tc;si();
while(tc--){
  int n;cin>>n;
  vector<int> fa(n+1);
  for(int i=1;i<=n;i++)make_set(i);
  vector<int> done(n+1);
  for(int i=2;i<=n;i++){
    if(primes[i]==i){
        debug(i);
        int val = 2*i;
        done[i]=1;
        if(val>n)continue;
        done[val]=1;
        union_sets(i,val);
        
    }
  }
  for(int i=2;i<=n;i++){
    if(!done[i]){
        int fac = primes[i];
        union_sets(i,fac);
    }
  }

  vector<vector<int> > v(n+1);
  for(int i=2;i<=n;i++){
    int par = find_set(i);
    v[par].push_back(i);
  }
  debug(v);
  fa[1]=1;
  for(auto it:v){
    if(it.size()==0)continue;
    debug(it);
    auto tmp = helper(it);
    debug(tmp);
    for(int i=0;i<it.size();i++){
        fa[it[i]]=tmp[i];
    }
  }
  for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
  cout<<endl;
  }
}