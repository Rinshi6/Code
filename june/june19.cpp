#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200010;
const long long MOD = 1000000007;

long long a[MAX_N], b[MAX_N], ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n + m + 1; ++i) cin >> a[i];
        for(int i = 0; i < n + m + 1; ++i) cin >> b[i];

        vector<pair<pair<long long, long long>, int>> v1, v2;
        for(int i = 0; i < n + m + 1; ++i) {
            if(a[i] > b[i]) v1.push_back({{a[i], b[i]}, i});
            else v2.push_back({{b[i], a[i]}, i});
        }

        if(v1.size() <= n) {
            swap(n, m);
            swap(v1, v2);
        }

        while(v1.size() > n + 1) {
            v2.push_back({{v1.back().first.second, v1.back().first.first}, v1.back().second});
            v1.pop_back();
        }

        long long sum = 0;
        for(auto& au : v1) sum += au.first.first;
        for(auto& au : v2) sum += au.first.first;

        for(auto& au : v1) ans[au.second] = sum - au.first.first;
        for(auto& au : v2) ans[au.second] = sum - au.first.first - v1.back().first.first + v1.back().first.second;

        for(int i = 0; i < n + m + 1; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}
