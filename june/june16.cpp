#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Increase the first candidate's fans by c
    a[0] += c;
    
    // Prefix sum array
    vector<long long> ps(n);
    ps[0] = a[0];
    for (int i = 1; i < n; ++i) {
        ps[i] = ps[i - 1] + a[i];
    }
    
    // Maximum votes encountered so far
    long long mx = -1,mi=-1;
    
    for (int i = 0; i < n; ++i) {
        if(a[i]>mx){
            mx=a[i];
            mi=i;
        }
    }
    
    // Calculate the minimum number of exclusions needed
    for (int i = 0; i < n; ++i) {
        if (i==mi)cout<<0<<" ";
        else if (ps[i] >= mx) {
            cout << i << " ";
        } else {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
