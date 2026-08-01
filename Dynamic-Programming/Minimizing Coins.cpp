// Question Link:- https://cses.fi/problemset/task/1634

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
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &coin : a)
        cin >> coin;

    const int INF = 1e9;
    vector<int> dp(x + 1, INF);

    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= a[j]) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    if (dp[x] == INF)
        cout << -1;
    else
        cout << dp[x];
}

int main() {
    fastio();
    solve();
    return 0;
}
