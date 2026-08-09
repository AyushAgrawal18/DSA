// https://codeforces.com/contest/2256/problem/C

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

bool valid(string &a, int x) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == '?') continue;
        int exp = (i % 2 == 0) ? x : 1 - x;
        if ((a[i] - '0') != exp) return false;
    }
    return true;
}

inline void solve() {
    // Your solution goes here
    int n;
    cin >> n;
    string s;
    cin >> s;

    string odd, even;
    for (int i = 0; i < n; i++) {
        if (i & 1) odd.push_back(s[i]);
        else even.push_back(s[i]);
    }

    ll cntOdd = (ll)valid(odd, 0) + (ll)valid(odd, 1);
    ll cntEven = (ll)valid(even, 0) + (ll)valid(even, 1);

    ll res = (cntOdd * cntEven) % MOD;
    cout << res << "\n";
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
