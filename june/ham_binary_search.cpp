#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a, b, c, pa, pb, pc, r, tp = 0, e = 0, l = 0, ca = 0, cb = 0, cc = 0, mid;

bool isvalid() {
    ll k = r;
    if ((ca * mid - a) > 0) k -= (ca * mid - a) * pa;
    if (k < 0) return false;
    if ((cb * mid - b) > 0) k -= (cb * mid - b) * pb;
    if (k < 0) return false;
    if ((cc * mid - c) > 0) k -= (cc * mid - c) * pc;
    if (k < 0) return false;
    return true;
}

int main() {
    string s;
    cin >> s >> a >> b >> c >> pa >> pb >> pc >> r;

    
    for (auto& x : s) {
        if (x == 'B') ca++;
        else if (x == 'S') cb++;
        else if (x == 'C') cc++;
    }

    
    if (ca > 0) e = max(e, a / ca);
    if (cb > 0) e = max(e, b / cb);
    if (cc > 0) e = max(e, c / cc);
    tp = ca * pa + cb * pb + cc * pc;
    e += r / tp+10;

    while (l <= e) {
        mid = l + (e - l) / 2;
        if (isvalid()) l = mid + 1;
        else e = mid - 1;
    }

    cout << l - 1 << endl;
    return 0;
}
