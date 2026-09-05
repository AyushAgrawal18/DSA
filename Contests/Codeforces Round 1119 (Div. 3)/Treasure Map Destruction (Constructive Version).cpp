// https://codeforces.com/contest/2259/problem/E
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

#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
#define loop for (int i = 0; i < n; i++)
#define rloop for (int i = n - 1; i >= 0; i--)
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double PI = acos(-1);

inline void solve()
{
    // Your solution goes here
    int n;
    cin >> n;
    vll a(n);
    loop cin >> a[i];

    vll diff(n + 1, 0);
    string ans(n, '0');
    bool pos = true;

    loop
    {
        if (a[i] == -1)
            continue;
        ll d = a[i];
        ll l = max(0LL, i - d + 1);
        ll r = min((n - 1LL), i + d - 1);
        if (l <= r)
        {
            diff[l]++;
            diff[r + 1]--;
        }
    }
    vector<bool> not_pos(n, false);
    int cur = 0;
    loop
    {
        cur += diff[i];
        if (cur > 0)
            not_pos[i] = true;
    }

    loop
    {
        if (a[i] == -1)
            continue;
        ll d = a[i];
        if (d == 0)
        {
            if (not_pos[i])
            {
                pos = false;
                break;
            }
            ans[i] = '1';
            continue;
        }
        else
        {
            ll l = i - d;
            ll r = i + d;
            if ((l < 0 || not_pos[l]) && (r >= n || not_pos[r]))
            {
                pos = false;
                break;
            }

            if (l >= 0 && !not_pos[l])
                ans[l] = '1';
            else
                ans[r] = '1';
        }
    }

    if (!pos)
    {
        cout << -1 << endl;
        return;
    }

    bool flag = false;
    loop
    {
        if (ans[i] == '1')
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        for (int i = 0; i < n; i++)
        {
            if (!not_pos[i])
            {
                ans[i] = '1';
                flag = true;
                break;
            }
        }
    }

    if (!flag)
    {
        cout << -1 << endl;
        return;
    }

    loop
    {
        cout << ans[i];
    }
    cout << endl;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
