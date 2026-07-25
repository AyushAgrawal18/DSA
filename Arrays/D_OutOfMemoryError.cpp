// Question Link: https://codeforces.com/problemset/problem/2185/D
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
     ll n,m,h;
     cin>>n>>m>>h;
     vll a(n);
     loop cin>>a[i];
     int reset=1;
     vll add(n,0);
     vll last(n,0);
     while(m--){
        ll b,c;
        cin>>b>>c;
        b--;
        if(last[b]!=reset){
            add[b]=0;
            last[b]=reset;
        }
        add[b]+=c;
        if((a[b]+add[b])>h){
            reset++;
        }
     }
     loop{
        if(last[i]!=reset){
            cout<<a[i]<<" ";
        }
        else{
            cout<<a[i]+add[i]<<" ";
        }
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
 