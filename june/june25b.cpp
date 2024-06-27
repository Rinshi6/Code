#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll x, y, k,cn=0;
    cin >> x >> y >> k;

    // If y is 1, just increment x by k
    if (y == 1) {
        cout << x + k << endl;
        return;
    }

    // Increment x by k
    x += k;

    // Perform Collatz-like transformation
    while (x % y ) {
        if(x%y){
            cn+=y-x%y;
            x-=y-x%y;
        }
        
        x /= y;
        if(cn>k)break;
    }

    // Output the final value of x
    cout << x+k%cn-cn << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
