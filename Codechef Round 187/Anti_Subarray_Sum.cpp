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
#define (x)
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
  ll n,x;cin>>n>>x;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  vector<ll> b(n);
  for(int i=0;i<n;i++)cin>>b[i];
 

 ll fa=-1e18;int fidx=n;int lidx=-1;
 for(int i=0;i<n;i++){
    if(a[i]>=0){
        if(fidx==n)fidx=i;
        lidx=i;
    }
 }

 segtree<ll> sg(a);
 
 vector<ll> pre(n);
 vector<ll> suff(n);
 vector<ll> f1(n);
 vector<ll> s1(n);
 vector<ll> t1(n,-1e18);
 vector<ll> t2(n,-1e18);


 for(int i=0;i<n;i++){
    if(i==0){
        if(a[i]>=0)pre[i]=a[i];
    }
    else{
        if(a[i]>=0)pre[i]=pre[i-1]+a[i];
        else pre[i]=pre[i-1];
    }
 }

 for(int i=n-1;i>=0;i--){
    if(i==n-1){
        if(a[i]>=0)suff[i]=a[i];
    }
    else{
        if(a[i]>=0)suff[i]=suff[i+1]+a[i];
        else suff[i]=suff[i+1];
    }
 }

 for(int i=0;i<n;i++){
    if(i==0){
        if(a[i]>=0){
            if(b[i])f1[i]=1;
        }
    }
    else if(f1[i-1])f1[i]=1;
    else{
        if(a[i]>=0 && b[i])f1[i]=1;
    }
 }

 for(int i=n-1;i>=0;i--){
    if(i==n-1){
        if(a[i]>=0 && b[i])s1[i]=1;
    }
    else if(s1[i+1])s1[i]=1;
    else{
        if(a[i]>=0 && b[i])s1[i]=1;
    }
 }



  for(int i=0;i<n;i++){
    if(i==0){
        if(a[i]<0 && b[i])t1[i]=a[i];
    }
    else{
        if(a[i]<0 && b[i])t1[i]=max(a[i],t1[i-1]);
        else t1[i]=t1[i-1];
    }
  }

  for(int i=n-1;i>=0;i--){
    if(i==n-1){
        if(a[i]<0 && b[i])t2[i]=a[i];
    }
    else{
        if(a[i]<0 && b[i])t2[i]=max(t2[i+1],a[i]);
        else t2[i]=t2[i+1];
    }
  }
  for(int i=1;i<n-1;i++){(i);
    //means 0...i-1 and i+1...n-1
    if(i-1>=fidx && i+1<=lidx){ll mxsum=pre[i-1]+suff[i+1];
        if(mxsum>=x){
            fa=max(fa,mxsum);
        }
        if(f1[i-1] || s1[i+1]){
            ll sm=pre[i-1]+suff[i+1];
            fa=max(fa,sm);
        }
        else{
            ll sm=pre[i-1]+suff[i+1]+max(t1[i-1],t2[i+1]);
            fa=max(fa,sm);
        }
    }
    else if(i-1>=fidx){ll mxsum=pre[i-1]+sg.query(i+1,n-1);
        if(mxsum>=x){
            fa=max(fa,mxsum);
        }
        if(f1[i-1]){
            ll sm=pre[i-1]+sg.query(i+1,n-1);
            fa=max(fa,sm);
        }
        else{
            ll sm1=t1[i-1]+sg.query(i+1,n-1)+pre[i-1];
            ll sm2=t2[i+1]+pre[i-1];
            fa=max({fa,sm1,sm2});
        }
    }
    else if(i+1<=lidx){ll mxsum=suff[i+1]+sg.query(0,i-1);
        if(mxsum>=x){
            fa=max(fa,mxsum);
        }
        if(s1[i+1]){
            ll sm=suff[i+1]+sg.query(0,i-1);
            fa=max(fa,sm);
        }
        else{
            ll sm1=t1[i-1]+suff[i+1];
            ll sm2=sg.query(0,i-1)+t2[i+1]+suff[i+1];
            fa=max({fa,sm1,sm2});
        }
    }
    else{ll mxsum=sg.query(0,i-1)+sg.query(i+1,n-1);
        if(mxsum>=x){
            fa=max(fa,mxsum);
        }

        ll sm1=t1[i-1]+sg.query(i+1,n-1);
        ll sm2=t2[i+1]+sg.query(0,i-1);
        fa=max({fa,sm1,sm2});
    }

  }

 ll more=x-fa;
 if(more<=0)cout<<0<<endl;
 else cout<<more<<endl;
  }
}