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
    int n, k;
    cin >> n >> k;
    int a = n / 2;
    int b = n - a;
    if(n-2 < k) {
        cout << -1 << endl;
        return;
    }
    vector <string> x;
    int turn = 0;
    for(int i = 0; i < n - k; i++) {
        if(turn == 0) {
            x.pb("0");
            b--;
        }
        else {
            x.pb("1");
            a--;
        }
        turn = 1 - turn;
    }
    while(a--) {
        x[1] += '1';
    }

    while(b--) {
        x[0] += '0';
    }
    
    for(auto &i : x) {
        cout<<i;
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
