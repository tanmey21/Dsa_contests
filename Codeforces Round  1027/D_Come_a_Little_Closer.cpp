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

template<typename T>
class segtree{
private:
    vector<T> seg;
    ll n;
    T merge(T a, T b){
        return max(a,b);
    }
    void build(vector<T>& a, ll tl, ll tr, ll v)
    {
        if(tl == tr){
            seg[v] = a[tl];
            return;
        }
        ll tm = (tl + tr)/2;
        build(a, tl, tm, 2*v+1);
        build(a, tm+1, tr, 2*v+2);
        seg[v] = merge(seg[2*v+1], seg[2*v+2]);
    }
    void update(ll tl, ll tr, ll pos, T val, ll v)
    {
        if(tl == tr){
            seg[v] = val;
            return;
        }
        ll tm = (tl + tr)/2;
        if(pos <= tm) update(tl, tm, pos, val, 2*v+1);
        else update(tm+1, tr, pos, val, 2*v+2);
        seg[v] = merge(seg[2*v+1], seg[2*v+2]);
    }
    T rangeval(ll tl, ll tr, ll l, ll r, ll v)
    {
        if(tl == l && tr == r) return seg[v];
        ll tm = (tl + tr)/2;
        if(r <= tm) return rangeval(tl, tm, l, r, 2*v+1);
        else if(l > tm) return rangeval(tm+1, tr, l, r, 2*v+2);
        return merge(rangeval(tl, tm, l, tm, 2*v+1), rangeval(tm+1, tr, tm+1, r, 2*v+2));
    }
public:
    segtree(ll n){
        seg.resize(4*n);
        this->n = n;
    }
    segtree(vector<T> a){
        this->n = (ll) a.size();
        seg.resize(4*n);
        build(a, 0, n - 1, 0);
    }
    void update(ll pos, T val){update(0, n - 1, pos, val, 0);}
    T query(ll l, ll r){return rangeval(0, n-1, l, r, 0);}
};

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  ll n;cin>>n;
  vector<pair<ll,ll> > a(n);
  for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;

  if(n==1){
    cout<<1<<endl;continue;
  }

  vector<int> t1(n);
  vector<int> t2(n);
  for(int i=0;i<n;i++)t1[i]=a[i].first;
  for(int i=0;i<n;i++)t2[i]=a[i].second;

  sort(t1.begin(),t1.end());
  sort(t2.begin(),t2.end());

  debug(t1);debug(t2);

  ll fa=1e18;

  for(int i=0;i<n;i++){
    int x=a[i].first;int y=a[i].second;
    int i1=0;int i2=n-1;int j1=0;int j2=n-1;
    if(t1[0]==x)i1++;
    else if(t1.back()==x)i2--;

    if(t2[0]==y)j1++;
    else if(t2.back()==y)j2--;

    debug(i1);
    debug(i2);
    debug(j1);
    debug(j2);

    ll x1=t1[i1];ll x2=t1[i2];ll y1=t2[j1];ll y2=t2[j2];
    ll l=n-1;
    ll p=(x2-x1+1)*(y2-y1+1);
    debug(p);
    if(p==l){
        ll p1=(x2-x1+2)*(y2-y1+1);
        ll p2=(x2-x1+1)*(y2-y1+2);

        p=min(p1,p2);
        fa=min(fa,p);
    }
    else{
        fa=min(fa,p);
    }

    debug(fa);
  }
  cout<<fa<<endl;
  }
}