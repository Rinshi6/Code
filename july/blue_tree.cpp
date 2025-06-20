#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvc = vector<vector<ll>>;

void solve() {
    ll n, a, b,c=5;
    cin >> n >> a >> b;
    a--, b--; // Convert to 0-based indexing
    c--;
    vvc graph(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--; // Convert to 0-based indexing
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<ll> parent(n, -1); // Parent array to track the parent of each node
    queue<ll> q;
    q.push(a); // Start BFS from node a

    // Perform BFS to find the parents of each node
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : graph[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            q.push(v);
        }
    }

    // Trace the path from b to a using the parent array
    vector<ll> path = {b};
    while (path.back() != a) {
        path.push_back(parent[path.back()]);
    }
    reverse(path.begin(), path.end());

    ll path_length = path.size();
    ll midpoint = path[(path_length - 1) / 2];
    ll res = path_length - (path_length + 1) / 2;

    vector<ll> dist(n, -1); // Distance array to track distances from the midpoint
    q.push(midpoint);
    dist[midpoint] = 0;

    // Perform BFS from the midpoint to calculate distances
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : graph[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    res += 2 * (n - 1) - *max_element(dist.begin(), dist.end()); // Calculate the result
    cout << res << endl; // Output the result
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    ll t;
    cin >> t; // Read the number of test cases
    while (t--) solve(); // Solve each test case
    return 0;
}
