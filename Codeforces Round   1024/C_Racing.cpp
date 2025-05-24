#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
#define pp pair<ll,ll>

int main() {
    fastio();
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<pp>> adj(n + 1);
        ll minW = LLONG_MAX, maxW = 0;
        for (int i = 0; i < m; i++) {
            ll x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            minW = min(minW, z);
            maxW = max(maxW, z);
        }

        auto canReach = [&](ll maxCost) -> bool {
            vector<ll> t(n + 1, -1);
            vector<bool> inQueue(n + 1, false);
            queue<ll> q;

            t[1] = a[0];
            q.push(1);
            inQueue[1] = true;

            while (!q.empty()) {
                ll node = q.front();
                q.pop();
                inQueue[node] = false;

                for (auto [next, cost] : adj[node]) {
                    if (cost > maxCost) continue;
                    if (t[node] >= cost) {
                        ll gain = t[node] + a[next - 1];
                        if (gain > t[next]) {
                            t[next] = gain;
                            if (!inQueue[next]) {
                                q.push(next);
                                inQueue[next] = true;
                            }
                        }
                    }
                }
            }

            return t[n] != -1;
        };

        ll s = minW, e = maxW, ans = -1;
        while (s <= e) {
            ll mid = (s + e) / 2;
            if (canReach(mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}
