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
    ll tc = 1;
    while (tc--) {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> adj[n + 1];
        for (ll i = 0; i < m; i++) {
            ll x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back(make_pair(y, z));
            adj[y].push_back(make_pair(x, z));
        }

        ll s = 1, e = (1LL << 30), fa = 0;
        while (s <= e) {
            ll mid = (s + e) / 2;
            ll flag = 0;

            for (ll i = 30; i >= 0; i--) {
                if (mid & (1LL << i)) {
                    ll val = (mid ^ (1LL << i));
                    vector<ll> dis(n + 1, 0);
                    dis[1] = 1;
                    queue<ll> q;
                    q.push(1);

                    while (!q.empty()) {
                        ll f = q.front(); q.pop();
                        for (auto it : adj[f]) {
                            ll node = it.first;
                            ll w = it.second;
                            if (dis[node]) continue;
                            ll flag2 = 1;
                            for (ll j = i; j <= 30; j++) {
                                if (w & (1LL << j)) {
                                    if (!(val & (1LL << j))) {
                                        flag2 = 0;
                                        break;
                                    }
                                }
                            }
                            if (flag2) {
                                dis[node] = 1;
                                q.push(node);
                            }
                        }
                    }

                    if (dis[n]) {
                        flag = 1;
                        break;
                    }
                }
            }

            if (flag) {
                fa = mid-1;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        cout << fa << endl;
    }
}
