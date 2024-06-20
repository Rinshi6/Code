#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void solve() {
    long long h;
    int n;
    cin >> h >> n;

    vector<int> a(n);
    vector<int> c(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> cooldownQueue;
    for (int i = 0; i < n; ++i) {
        cooldownQueue.push({0, i});
    }

    long long currentTurn = 0;
    while (h > 0) {
        currentTurn = cooldownQueue.top().first;

        long long totalDamage = 0;
        vector<pair<long long, int>> nextCooldowns;
        while (!cooldownQueue.empty() && cooldownQueue.top().first == currentTurn) {
            int idx = cooldownQueue.top().second;
            cooldownQueue.pop();
            totalDamage += a[idx];
            nextCooldowns.push_back({currentTurn + c[idx], idx});
        }
        for (const auto& nc : nextCooldowns) {
            cooldownQueue.push(nc);
        }
        h -= totalDamage;
        if (totalDamage == 0 && !cooldownQueue.empty()) {
            currentTurn = cooldownQueue.top().first;
        }
    }

    cout << currentTurn+1<< endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
