#include <bits/stdc++.h>

using namespace std;
string s;
int n, k, res;
void check(int a) {
    if (res) return;
    reverse(s.begin()+a, s.end());
    bool jo=1;
    for (int i=1; i<k; i++) {
        if (s[i]!=s[i-1]) jo=0;
    }
    for (int i=k; i<n; i++) {
        if (s[i]==s[i-k]) jo=0;
    }
    if (jo) {
        res=a;
    }
    reverse(s.begin()+a, s.end());
}
void solve() {
    cin >> n >> k >> s;
    check(n);
    int spec=0;
    for (auto x:s) {
        if (x==s.back()) {
            spec++;
        } else {
            spec=0;
        }
    }
    if (spec>k) {
        check(n-spec);
    }

    int len=1;
    for (int i=1; i<n; i++) {
        if (s[i]!=s[i-1]) {
            if (len<k) {
                check(i);
                break;
            }
            len=1;
        } else {
            if (len==k) {
                check(i);
                if (spec<=k) {
                    check(i-spec);
                }
                break;
            }
            len++;
        }
    }
    //cout << "valasz........... ";
    if (res) {
        cout << res << "\n";
    } else {
        cout << -1 << "\n";
    }
    res=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
