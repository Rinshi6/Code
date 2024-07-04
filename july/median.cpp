#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int median=0;
    for (int i = 0; i < n-1; ++i) {
        median=max(median,min(a[i],a[i+1]));
    }
    for (int i = 0; i < n-2; ++i) {
        median=max(median,min(a[i],a[i+2]));
    }
    

    cout<<median<<endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
