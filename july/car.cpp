#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1, 0);
    vector<int> b(k + 1, 0);
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    while (q--) {
        int val;
        cin >> val;
        if (val == 0) {
            cout << 0 << " ";
            continue;
        }

        int i = int(lower_bound(a.begin(), a.end(), val) - a.begin());
        if (i > k) i = k;

        if (a[i] == val) {
            cout << b[i] << " ";
        } else {
            double prev = b[i - 1];
            prev += ((double)(val - a[i - 1]) * (b[i] - b[i - 1]) / (a[i] - a[i - 1]));
            cout << (int)prev << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
