#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n + 1);
    bool alreadySorted = true;
    
    for (int i = 1; i <= n; ++i) {
        cin >> ar[i];
        if (ar[i] != i) {
            alreadySorted = false;
        }
    }
    
    if (k == 1) {
        if (alreadySorted) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    vector<int> vis(n + 1, 0);
    bool isValid = true;

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        
        int x = i;
        bool hasCycle = false;
        vis[i] = i;
        
        while (true) {
            x = ar[x];
            if (vis[x] == i) {
                hasCycle = true;
                break;
            }
            if (vis[x] > 0) break;
            vis[x] = i;
        }
        
        if (hasCycle) {
            int cycleLength = 0;
            int start = x;
            
            do {
                x = ar[x];
                cycleLength++;
            } while (x != start);
            
            if (cycleLength != k) {
                isValid = false;
                break;
            }
        }
    }
    
    if (isValid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int qt;
    cin >> qt;
    while (qt--) {
        solve();
    }

    return 0;
}
