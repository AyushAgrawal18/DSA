#include <bits/stdc++.h>
using namespace std;

/* 
  ****************************************************
  *                                                  *
  *             COMPETITIVE PROGRAMMING              *
  *                                                  *
  *            Author: Ayush Kumar Agrawal           *
  *                  Code Smart, Win Big             *
  *                                                  *
  ****************************************************
*/

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
#define loop for(int i = 0; i < n; i++)
#define rloop for(int i = n-1; i >= 0; i--)
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double PI = acos(-1);

inline void solve() {
    // Your solution goes here

        auto getCount = [&](int l, int r) -> ll {
            if (l > r || l > m) return 0LL;
            r = min(r, m);
            return pref[r] - pref[l - 1];
        };


        int n, m;
        cin >> n >> m;

        vll freq(m + 1);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
            sum += x;
        }
        vll pref(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            pref[i] = pref[i - 1] + freq[i];
        }
        

        vll ans(m + 1);
        int maxi = 0;
        while ((1LL << maxi)<m)
            maxi++;

        for (int k = 1; k <= m; k++) {
            if (k >= maxi) {
                ans[k] = sum;
                continue;
            }

            long long C = 1LL << k;
            long long best = 0;

            for (int x = 1; x <= m; x++) {

                long long high = 0;

                long long firstHigh = (C + 1) * 1LL * x;

                if (firstHigh <= m) {
                    high = getCount((int)firstHigh, m);
                }

                long long cur = high * (C - 1);

                int lim = min<long long>(C, m / x);

                for (int q = 1; q <= lim; q++) {
                    int l = q * x;
                    int r = min(m, (q + 1) * x - 1);

                    long long cnt = getCount(l, r);
                    cur += cnt * q;
                }

                best = max(best, cur);
            }

            ans[k] = best;
        }

        for (int k = 1; k <= m; k++) {
            cout << ans[k] << (k == m ? '\n' : ' ');
        }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
