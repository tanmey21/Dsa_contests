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

vector<ll> helper(vector<ll> &a, ll idx, ll sm) {
    vector<ll> fa;
    ll n = a.size();
    ll before = sm;
    for (ll i = 0; i < n; i++) {
        if (i <= idx) {
            if (a[i] <= sm) {
                fa.push_back(a[i]);
                sm -= a[i];
            } else {
                fa.push_back(sm);
                sm = 0;
            }
        } else {
            if (i == idx + 1) sm = before;
            if (a[i] <= sm) {
                fa.push_back(a[i]);
                sm -= a[i];
            } else {
                fa.push_back(sm);
                sm = 0;
            }
        }
    }
    return fa;
}

int main() {
    fastio();
    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];

        vector<ll> pre(n), suff(n);
        for (ll i = 0; i < n; i++) {
            if (i == 0) pre[i] = a[i];
            else pre[i] = pre[i - 1] + a[i];
        }
        for (ll i = n - 1; i >= 0; i--) {
            if (i == n - 1) suff[i] = a[i];
            else suff[i] = suff[i + 1] + a[i];
        }

        ll idx = -1;
        for (ll i = 0; i < n - 1; i++) {
            if (pre[i] == suff[i + 1]) {
                idx = i; break;
            }
        }

        vector<pair<ll, ll>> v1(n);
        for (ll i = 0; i < n; i++) {
            if (i == 0) v1[i] = make_pair(0, 0);
            else if (i == 1) {
                if (a[1] < a[0]) v1[i] = make_pair(1, 0);
                else v1[i] = make_pair(0, 1);
            } else {
                ll idx1 = v1[i - 1].first;
                ll idx2 = v1[i - 1].second;
                if (a[i] > a[idx2]) {
                    idx1 = idx2;
                    idx2 = i;
                } else if (a[i] > a[idx1]) {
                    idx1 = i;
                }
                v1[i] = make_pair(idx1, idx2);
            }
        }

        if (idx != -1) {
            cout << 1 << endl;
            for (auto it : a) cout << it << " ";
            cout << endl;
            continue;
        }

        vector<vector<ll>> total_ans;
        ll fa = 1e9;
        for (ll i = 0; i < n - 1; i++) {
            ll sm1 = pre[i], sm2 = suff[i + 1];
            if (i == 0 && sm1 > sm2) continue;
            if (i == n - 1 && sm2 > sm1) continue;
            ll d = abs(sm1 - sm2);
            if (d % 2) continue;
            d /= 2;

            ll flag = 0;
            if (sm2 > sm1) flag = 1;
          

            if (!flag) {
                idx = -1;
                for (ll j = 0; j < i; j++) {
                    ll t1 = pre[j], t2 = suff[j + 1] - suff[i + 1];
                    if (t1 >= d && t2 >= d) {
                        idx = j; break;
                    }
                }
                if (idx == -1) continue;
                vector<ll> tmp;
                for (ll j = 0; j <= i; j++) tmp.push_back(a[j]);
                auto ans = helper(tmp, idx, d);
                for (ll j = i + 1; j < n; j++) ans.push_back(0);
                total_ans.push_back(ans);
                for (ll j = 0; j < n; j++) a[j] -= ans[j];
                total_ans.push_back(a);
                break;
            } else {
                idx = -1;
                for (ll j = i + 1; j < n - 1; j++) {
                    ll t1 = pre[j] - pre[i], t2 = suff[j + 1];
                    if (t1 >= d && t2 >= d) {
                        idx = j; break;
                    }
                }
               
                if (idx == -1) continue;
                vector<ll> tmp;
                for (ll j = i + 1; j < n; j++) tmp.push_back(a[j]);
                auto ans = helper(tmp, idx - (i + 1), d);
                
                vector<ll> a2;
                for (ll j = 0; j <= i; j++) a2.push_back(0);
                for (auto it : ans) a2.push_back(it);
                total_ans.push_back(a2);
                for (ll j = 0; j < n; j++) a[j] -= a2[j];
                total_ans.push_back(a);
                break;
            }
        }

        if (total_ans.empty()) {
            cout << -1 << endl;
            continue;
        }

        cout << 2 << endl;
        for (auto &row : total_ans) {
            for (auto val : row) cout << val << " ";
            cout << endl;
        }
    }
}
