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
  int w,h,a,b;cin>>w>>h>>a>>b;
  int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
  pair<int,int> i1,i2,i3,i4;
  i1=make_pair(x1,x1+a-1);
  i2=make_pair(y1,y1+b-1);
  i3=make_pair(x2,x2+a-1);
  i4=make_pair(y2,y2+b-1);

  
    if(i1.first>i3.first)swap(i1,i3);
    if(i2.first>i4.first)swap(i2,i4);
  int d1=0;int d2=0;

  if(i1.second>i3.first){
    d1=-1;
  }
  else d1=i3.first-i1.second;

  if(i2.second>i4.first)d2=-1;
  else d2=i4.first-i2.second;

  d1--;d2--;
  
  debug(i1);
  debug(i2);
  debug(i3);
  debug(i4);

  debug(d1);debug(d2);
  
  if((d1%a ==0 && d1>=0)|| (d2%b==0 && d2>=0))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  }
}