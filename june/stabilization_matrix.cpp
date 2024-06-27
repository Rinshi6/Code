#include <bits/stdc++.h>
using namespace std;
#define ll long long



void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    
    auto isPeak = [&](int i, int j) -> bool {
        int val = v[i][j];
        if (i > 0 && val <= v[i-1][j]) return false;
        if (i < n-1 && val <= v[i+1][j]) return false;
        if (j > 0 && val <= v[i][j-1]) return false;
        if (j < m-1 && val <= v[i][j+1]) return false;
        return true;
    };
    auto peakValue = [&](int i, int j) -> int {
        int val = INT_MIN;
        if (i > 0 && val<v[i-1][j]) val=max(v[i-1][j],val);
        if (i < n-1 && val < v[i+1][j]) val=max(v[i+1][j],val);
        if (j > 0 && val < v[i][j-1]) val=max(val,v[i][j-1]);
        if (j < m-1 && val < v[i][j+1]) val=max(val,v[i][j+1]);
        return val;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPeak(i, j)) 
                v[i][j]=peakValue(i,j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
