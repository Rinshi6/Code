#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n-1);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n - 1; ++i) b[i] = __gcd(a[i], a[i + 1]);

        int idx = -1;
        for (int i = 0; i < n - 2; ++i) {
            if (b[i] > b[i + 1]) {
                idx = i;
                break;
            }
        }

        vector<int> a1, a2, a3;
        for (int i = 0; i < n; ++i) {
            if (i != idx + 1) a1.push_back(a[i]);
            if (i != idx + 2) a2.push_back(a[i]);
            if (i != idx) a3.push_back(a[i]);
        }

        vector<int> b1(a1.size() - 1), b2(a2.size() - 1), b3(a3.size() - 1);

        for (int i = 0; i < a1.size() - 1; ++i) {
            b1[i] = __gcd(a1[i], a1[i + 1]);
        }

        for (int i = 0; i < a2.size() - 1; ++i) {
            b2[i] = __gcd(a2[i], a2[i + 1]);
        }

        for (int i = 0; i < a3.size() - 1; ++i) {
            b3[i] = __gcd(a3[i], a3[i + 1]);
        }

        bool f1 = is_sorted(b1.begin(), b1.end());
        bool f2 = is_sorted(b2.begin(), b2.end());
        bool f3 = is_sorted(b3.begin(), b3.end());

        if (!(f1 || f2 || f3)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
