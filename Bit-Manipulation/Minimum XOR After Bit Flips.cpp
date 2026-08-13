#include <bits/stdc++.h>
using namespace std;

int minimumXor(vector<int>& a, int k) {
    int x = 0;
    for (int v : a)
        x ^= v;

    for (int b = 30; b >= 0 && k > 0; b--) {
        if (x & (1 << b)) {
            x ^= (1 << b);
            k--;
        }
    }
    return x;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    cin >> k;

    cout << minimumXor(a, k);
}