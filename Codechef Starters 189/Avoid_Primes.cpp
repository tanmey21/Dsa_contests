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



const int N=2e5+5;
vector<int> primes(N,-1);

void si(){
    for(int i=2;i<N;i++){
        if(primes[i]!=-1)continue;
        for(int j=2;i*j<N;j++){
            primes[i*j]=0;
        }
    }
}
int tmpn;

vector<int> solve(int n){
    vector<int> a;
    for(int i=1;i<=n;i++)a.push_back(i);

    int fa=1e9;
    vector<int> ans;

    do {int c=0;
        for(int i=0;i<n-1;i++){
            int t=min(a[i],a[i+1]);
            if(primes[t]==-1)c++;
        }
        fa=min(fa,c);
    } while(std::next_permutation(a.begin(), a.end()));

    debug(fa);

    do {int c=0;
        for(int i=0;i<n-1;i++){
            int t=min(a[i],a[i+1]);
            if(primes[t]==-1)c++;
        }
       if(c==fa){
        if(n<7){
            for(auto it:a)ans.push_back(it);
        return ans;
        }
        else{
            if(primes[a[0]]==0){
                for(auto it:a)ans.push_back(it);
        return ans;
            }
        }
       }
    } while(std::next_permutation(a.begin(), a.end()));
}

int check(vector<int> &a){int c=0;int n=a.size();
    for(int i=0;i<n-1;i++){
        int v=min(a[i],a[i+1]);
        if(primes[v]==-1)c++;
    }
    return c;
}
vector<int> tmp;
int main() {
fastio();
int tc;cin>>tc;si();primes[1]=0;
tmp=solve(7);
while(tc--){
  int n;cin>>n;
  tmpn=n;
  if(n<7){
    vector<int> fa=solve(n);
    debug(fa);
    // cout<<check(fa)<<endl;
    for(auto it:fa)cout<<it<<" ";
    cout<<endl;
  }
  else{
    vector<int> fa;
    vector<int> v1;vector<int> v2;
    for(int i=n;i>=8;i--){
        if(primes[i]==-1)v2.push_back(i);
        else v1.push_back(i);
    }
    set<int> s1;set<int> s2;
    for(auto it:v1)s1.insert(it);
    for(int i=0;i<v2.size();i++){
        int val=v2[i];
        auto it=s1.lower_bound(val);
        --it;
        int a1=*it;
        --it;
        int a2=*it;
        fa.push_back(a1);
        fa.push_back(val);
        fa.push_back(a2);
        s1.erase(a1);
        s1.erase(a2);
    }
    for(auto it:s1)fa.push_back(it);
    for(auto it:tmp)fa.push_back(it);
    // cout<<check(fa)<<endl;
    for(auto it:fa)cout<<it<<" ";
    cout<<endl;
  }
  }
}