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
     int n;
    cin >> n;

    vector<vector<int>> a(n + 1);

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        a[p].push_back(i);
    }

    vector<int> p;
    p.reserve(n);
    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        p.push_back(v);
        for (int u : a[v])
            st.push(u);
    }

    reverse(p.begin(), p.end());

    vector<vector<int>> b(n + 1);

    int m = n + 1;
    int ans = n;

    map<vector<int>, int> mp;

    for (int v : p) {

        b[v].push_back(v);

        int maxi = 0;

        for (int u : a[v])
            maxi = max(maxi, (int)b[u].size());

        for (int d = 0; d < maxi; d++) {

            vector<int> cur;

            for (int u : a[v]) {
                if (d < b[u].size())
                    cur.push_back(b[u][d]);
            }

            if (cur.empty())
                break;

            if (cur.size() == 1) {
                b[v].push_back(cur[0]);
            } 
            else {

                sort(cur.begin(), cur.end());

                auto it = mp.find(cur);

                if (it == mp.end()) {
                    mp[cur] = m;
                    b[v].push_back(m++);
                    ans++;
                } else {
                    b[v].push_back(it->second);
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
