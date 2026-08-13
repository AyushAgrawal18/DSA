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
    int t, k;
    int n=1e5;
    cin>>t>>k;
    vi f(n+1);
    vi p(n+1);
 
    for (int i = 1;i<k;i++)f[i] = 1;
    f[k] = 2;
    for (int i = k + 1;i<=n;i++)f[i] = (f[i - 1] + f[i - k])%MOD;
    for (int i = 1;i<=n;i++)p[i] = (p[i - 1] + f[i])%MOD;
    while (t--){
        int a,b;
        cin>>a>>b;
        int ans = (p[b] - p[a - 1])%MOD;
        if (ans < 0)ans += MOD;
        cout<<ans<<'\n';
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
