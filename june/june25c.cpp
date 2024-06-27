#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int left = 0, right = 0;
    ll current_sum = 0;
    int rounds = 0;
    
    while (right < n) {
        current_sum += a[right];
        
        while (current_sum > r && left <= right) {
            current_sum -= a[left];
            left++;
        }
        

        if (current_sum >= l && current_sum <= r) {
            rounds++;
            current_sum=0;
            left = right + 1; 
        }
        
        right++;
    }
    
    cout << rounds << "\n";
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
