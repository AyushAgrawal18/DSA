// https://codeforces.com/contest/1036/problem/C

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

vector<long long> res;

void brute(int pos, int cnt, long long cur){
    if (pos == 18){
        res.push_back(cur);
        return;
    }
    brute(pos+1, cnt, cur*10);
    if (cnt<3)
        for (int i=1; i<=9; i++)
            brute(pos+1, cnt+1, cur*10+i);
}

inline void solve() {
    // Your solution goes here
    ll l,r;
    cin>>l>>r;
    cout<<upper_bound(res.begin(),res.end(),r)-lower_bound(res.begin(), res.end(), l)<<endl;
}

int main() {
    fastio();
    brute(0, 0, 0);
    res.push_back(1e18);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
