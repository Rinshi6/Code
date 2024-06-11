#include <bits/stdc++.h>
using namespace std;

bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back({x, i});
        }
        sort(v.begin(), v.end(), comparator);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[v[i].second] = i + 1;
        }
        for (auto y : ans) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
