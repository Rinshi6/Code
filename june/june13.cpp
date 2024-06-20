#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long f(vector<long long>& a, long long k, int n) {
    long long m = a[0];
    int j = 0;
    for (int i = 0; i < n-1; ++i) {
        long long d = a[i+1] - a[i];
        long long e = (i+1) * d;
        if (k >= e) {
            k -= e;
            j = i+1;
            m = a[j];
        } else {
            m += k / (i+1);
            k %= (i+1);
            break;
        }
    }

    if (k > 0) {
        m += k / n;
        k %= n;
    }

    long long ans = m * n + (k - j);
    return ans;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << f(a, k, n) << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
