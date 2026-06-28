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

const int MAXN = 1e6 + 5;
vi sp(MAXN, 0);

void sieve() {
    rep(i, 2, MAXN) {
        if (sp[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                if (sp[j] == 0) sp[j] = i;
            }
        }
    }
}

inline void solve() {
    // Your solution goes here
    int n;
    cin>>n;
    int a=0,b=0;
    while(n>1) {
        int p=sp[n];
        a++;
        while(n%p==0) {
            n/=p;
            b++;
        }
    }
    cout<<b+a-1<<"\n";
}

int main() {
    fastio();
    sieve();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
