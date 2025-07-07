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

int Check(vector<int> &a){int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]!=a[n-1-i])return 0;
    }
    return 1;
}

bool canBePalindrome(vector<int>& vec, int el, int x) {
    int l = 0, r = vec.size() - 1;
    int removals = 0;

    while (l < r) {
        if (vec[l] == vec[r]) {
            l++;
            r--;
        } else if (vec[l] == el) {
            l++;
            removals++;
        } else if (vec[r] == el) {
            r--;
            removals++;
        } else {
            return false; // mismatch with non-el
        }
        if (removals > x) return false;
    }
    return true;
}

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n,k;cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  if(k==1 || Check(a)){
    cout<<"Yes"<<endl;continue;
  }
  vector<int> b=a;
  sort(b.begin(),b.end());
  int fidx=n-1;
  for(int i=k-2;i<n;i++){
    if(b[i]!=b[k-2]){
        fidx=i-1;break;
    }
  }

 

  while(b.size()!=fidx+1)b.pop_back();

  if(b.size()==k-1){set<int> st;
    for(auto it:b)st.insert(it);
    vector<int> v;
    for(auto it:a){
        if(st.count(it))v.push_back(it);
    }
    if(Check(v))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else{
    int rem = b.back();//means we can remove rem and number of times  is times
    int times = b.size()-(k-1);
    vector<int> v;
    set<int> st;
    for(auto it:b)st.insert(it);
    for(int i=0;i<n;i++){
        if(st.count(a[i]))v.push_back(a[i]);
    }
    auto fa = canBePalindrome(v,rem,times);
    if(fa)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }

  }
}