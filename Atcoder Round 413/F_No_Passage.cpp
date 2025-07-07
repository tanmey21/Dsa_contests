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
        ll n, m, k; cin >> n >> m >> k;
        vector<pair<ll, ll>> a(k);
        for (ll i = 0; i < k; i++) cin >> a[i].first >> a[i].second;
        
        vector<vector<ll>> dp(n, vector<ll>(m, 1e15));
        queue<pair<ll, ll>> q;

        for (auto it : a) {
            q.push(make_pair(it.first - 1, it.second - 1));
            dp[it.first - 1][it.second - 1] = 0;
        }

        while (!q.empty()) {
            auto f = q.front(); q.pop();
            ll curr_x = f.first, curr_y = f.second;
            
            ll dx[] = {1, 0, -1, 0};
            ll dy[] = {0, 1, 0, -1};
            for (ll j = 0; j < 4; j++) {
                ll x_new = curr_x + dx[j];
                ll y_new = curr_y + dy[j];
                if (x_new >= 0 && y_new >= 0 && x_new < n && y_new < m) {
                    ll mi1 = 1e15, mi2 = 1e15;
                    
                    for (ll i = 0; i < 4; i++) {
                        ll x = x_new + dx[i];
                        ll y = y_new + dy[i];
                        if (x >= 0 && y >= 0 && x < n && y < m) {
                            if (dp[x][y] < mi1) {
                                mi2 = mi1;
                                mi1 = dp[x][y];
                            } else if (dp[x][y] < mi2) {
                                mi2 = dp[x][y];
                            }
                        }
                    }
                    if (dp[x_new][y_new] > mi2 + 1) {
                        dp[x_new][y_new] = mi2 + 1;
                        q.push(make_pair(x_new, y_new));
                    }
                }
            }
        }

        ll fa = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (dp[i][j] < 1e15) {
                    fa += dp[i][j];
                }
            }
        }
        cout << fa << endl;
    }
}
