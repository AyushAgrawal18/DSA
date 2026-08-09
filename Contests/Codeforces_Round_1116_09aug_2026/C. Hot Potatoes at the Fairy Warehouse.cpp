// https://codeforces.com/contest/2256/problem/C

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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll odd=0,even=0;
    ll x=2*n;
    for(int i=0;i<x-1;i++){
        if(s[i]=='1'&&s[i+1]=='0'){
            if(i&1){
                odd++;
            }
            else{
                even++;
            }
        }
        else if(s[i]=='1'&&s[i+1]=='1'){
            if(i&1){
                even++;
            }
            else{
                odd++;
            }
        }
    }
    if(s[x-1]=='1'&&s[0]=='0'){
        odd++;
    }
    else if(s[x-1]=='1'&&s[0]=='1'){
        even++;
    }
    cout<<even<<" "<<odd<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
