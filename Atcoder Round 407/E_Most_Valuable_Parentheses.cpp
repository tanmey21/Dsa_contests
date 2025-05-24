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

const int INF = INT_MIN;

class SegmentTree {
    int n;
    vector<pair<int, int>> tree;  // pair<value, index>

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    void build(const vector<int>& data, int node, int l, int r) {
        if (l == r) {
            tree[node] = {data[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(data, 2 * node, l, mid);
        build(data, 2 * node + 1, mid + 1, r);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) return a;
        if (b.first > a.first) return b;
        return (a.second < b.second) ? a : b;
    }

    pair<int, int> query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    pair<int, int> query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return {INF, INT_MAX};  // neutral value

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        auto left = query(2 * node, start, mid, l, r);
        auto right = query(2 * node + 1, mid + 1, end, l, r);
        return combine(left, right);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = {value, idx};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, value);
        else
            update(2 * node + 1, mid + 1, end, idx, value);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
};


int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n;cin>>n;
  vector<int> a(2*n);int sz=2*n;
  for(int i=0;i<2*n;i++)cin>>a[i];
  

  SegmentTree st(a);ll fa=0;
  for(int i=0;i<n;i++){
    auto it=st.query(0,2*i);
    fa+=it.first;
    int idx=it.second;
    st.update(idx,INF);
  }
  
cout<<fa<<endl;
 
 
  }
}