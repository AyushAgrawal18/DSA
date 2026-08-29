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
    int n, m;
    cin >> n >> m;
    vector<int> freq(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        freq[x]++;
    }
    int ans=0;
    for (int i =1;i<=m;i++) {
        ans = max(ans, freq[i]);
    }
    vector<int> mx(m+2, 0);
    for (int i=m;i>=1;i--) {
        mx[i]=max(mx[i+1], freq[i]);
    }
    for (int y=1;y<=m;y++) {
        ans = max(ans,freq[y]+mx[y + 1]);
    }
    int great = 0;
    for (int y=m;y>=1;y--) {
        int cur=freq[y]+great;
        if (2*y<=m) {
            cur+=freq[2*y];
        }
        ans = max(ans, cur);
        great += freq[y];
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
