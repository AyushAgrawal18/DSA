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

ll res(ll a,ll b,ll p,ll q,ll r, vector<vector<ll>>& dp){
    if(a==0 && b==0) return 0;
    if(a<0 || b<0) return INF;
    if(dp[a][b]!=-1) return dp[a][b];
    ll left = res(a-1,b,p,q,r,dp) + p;
    ll left2 = res(a-2,b,p,q,r,dp) + p;
    ll right = res(a,b-1,p,q,r,dp) + q;
    ll right2 = res(a,b-2,p,q,r,dp) + q;
    ll diag = res(a-1,b-1,p,q,r,dp) + r;
    return dp[a][b] = min({left, left2, right, right2, diag});
}

inline void solve() {
    // Your solution goes here
    ll a,b,p,q,r;
    cin>>a>>b>>p>>q>>r;
    vector<vector<ll>> dp(a+1, vector<ll>(b+1, -1));
    ll ans=res(a,b,p,q,r,dp);
    cout<<ans<<"\n";
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
