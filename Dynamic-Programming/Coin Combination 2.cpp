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

int result(int i, int x, vll &a, vector<vll> &dp){
    
    if(x == 0) return 1;
    if(i == a.size()) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    int take = 0;
    if(x>=a[i]){
        take=result(i, x-a[i], a, dp);
    }
    int nott= result(i+1, x, a, dp);

    return dp[i][x]=(take+nott)%MOD;
}

inline void solve() {
    // Your solution goes here
    ll n, x;
    cin>>n>>x;
    vll a(n);
    loop cin>>a[i];
    vector<vll> dp(n, vll(x+1,-1));
    int ans=result(0,x,a,dp);
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
