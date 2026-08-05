// Question Link: https://codeforces.com/contest/2254/problem/B

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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) ans++;
    }
    ll res = 1e18;
    for(int i = 1; i < n - 1; i++) {
        ll temp = ans;
        if (s[i-1] != s[i]) temp--;
        if (s[i] != s[i+1]) temp--;
        if (s[i-1] != s[i+1]) temp++;
        res = min(res, temp);
    }
    cout<<res<<'\n';
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
