// Question Link: https://codeforces.com/problemset/problem/2232/C1

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
        ll n,t,s;
        cin>>n>>t>>s;
        string str;
        cin>>str;
        ll l = 0, r = 0, ans = 0;
        for(char c: str){
            if(c == 'A'){
                if(t * s == ans) continue;

                ans++;
                if(ans > l * s) l++;
                r = min(t, r + 1);
            }
            else if(c == 'I'){
                if(l == t) continue;

                ans++;
                l++;
                r = min(t, r + 1);
            }
            else if(c == 'E'){
                if(ans == r * s) continue;

                ans++;
                if(ans > l * s) l++;
            }
        }
        cout << ans << "\n";
    
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
