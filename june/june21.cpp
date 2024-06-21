#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
 
 
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a;
 
    int bit = 0;
    for (bit = 30; bit >= 0; bit--) if (k & (1 << bit)) break;
 
    for (int i = 1; i <= 1000000; i *= 2) if (i != (1 << bit)) a.pb(i);
    a.pb(k - (1 << bit));
    a.pb(k + 1);
    a.pb(3 * k);
    a.pb(2 * k);
    a.pb(2 * k + 1);
    cout << a.size() << "\n";
    sort(a.begin(), a.end());
    for (auto j : a) cout << j << " ";
    cout << "\n";
}
 
 
int main() { 
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}