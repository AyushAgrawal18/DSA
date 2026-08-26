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
        int n;
        cin >> n;
        vll a(n);
        for (auto &x : a) cin >> x;
        string s;
        cin >> s;
        ll mx1 = 0, mx2 = 0;
        int i = 0;
        while (i < n) {
            ll run = a[i];
            int j = i;
            while (j < n && s[j] == s[i]) {
                run = max(run, a[j]);
                j++;
            }
            if (run >= mx1) {
                mx2 = mx1;
                mx1 = run;
            } 
            else if (run > mx2) {
                mx2 = run;
            }

            i = j;
        }
        if (s[0] == s[n-1]) {
            mx1=mx2=0;
            int k = 0;
            while (k<n-1&&s[k] ==s[k+1])
                k++;

            k= (k+1)%n;
            int cnt = 0;
            i = k;

            while (cnt < n) {
                ll run = a[i];
                int j = i;
                while (cnt < n && s[j] == s[i]) {
                    run = max(run, a[j]);
                    j = (j + 1) % n;
                    cnt++;
                }
                if (run >= mx1) {
                    mx2 = mx1;
                    mx1 = run;
                } 
                else if (run > mx2) {
                    mx2 = run;
                }
                i = j;
            }
        }
        cout << mx1 + mx2 << '\n';

}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
