// https://codeforces.com/contest/2256/problem/D

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

const ll MOD = 998244353;
const ll INF = 1e18;
const double PI = acos(-1);

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}
inline void solve() {
    // Your solution goes here
    ll n; 
    string s;
    cin >> n >> s;
    vll c[2];
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        c[s[i] - '0'].push_back(j - i);
        i = j;
    }
    vll a(n + 1, 1), b(n + 1, 1);
    for (int i = 1; i <= n; i++) a[i] = a[i-1] * i % MOD;
    b[n] = pw(a[n], MOD - 2);
    for (int i = n; i>0; i--) b[i-1] = b[i] * i % MOD;
    ll ans = 1;
    for (auto v : c) {
        map<int,int> mp;
        for (int x : v) mp[x]++;
        ans = ans * a[v.size()] % MOD;
        for (auto x : mp){
            int y=x.second;
            ans=ans*b[y]%MOD;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
