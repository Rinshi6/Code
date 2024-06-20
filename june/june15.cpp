#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    vector<vector<int>> v(k);
    vector<bool> f(k, false);  // Initialize with false
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int c = 0;
        for (int j = 0; j < k; j++) {
            if (s[i][j] == 'o') {
                c++;
                v[j].push_back(i);
            }
        }
        a[i] = c;
    }

    int c = 0;
    int ans = 0;
    while (c < k) {
        int mx = 0, mi = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) {
                mx = a[i];
                mi = i;
            }
        }

        for (int i = 0; i < k; i++) {
            if (s[mi][i] == 'o' && !f[i]) {
                c++;
                for (int idx : v[i]) {
                    a[idx]--;
                }
                f[i] = true;
            }
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}
