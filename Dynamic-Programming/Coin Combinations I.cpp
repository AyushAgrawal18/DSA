// https://cses.fi/problemset/task/1635

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

int result(int x, vll &a, vll &dp){
    
    if(x == 0) return 1;
    // if(x < 0) return 0;
    if(dp[x]!=-1) return dp[x];
    int take = 0;
    for(int i = 0; i < a.size(); i++){
        take = (take + result(x - a[i], a, dp)) % MOD;
    }

    return dp[x] = take;
}

inline void solve() {
    // Your solution goes here
    ll n, x;
    cin>>n>>x;
    vll a(n);
    loop cin>>a[i];
    vll dp(x+1,-1);
    int ans=result(x,a,dp);
    cout<<ans;
}

int main() {
    fastio();
    // int t;
    // cin >> t;
    // while (t--) 
    solve();
    return 0;
}
