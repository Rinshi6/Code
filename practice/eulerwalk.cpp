#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int X = 300001;
bool sieve[X];
vector<int> primes;

using pii = pair<int, int>;
using vi = vector<int>;

vector<int> eulerWalk(vector<vector<pii>>& graph, int num_edges, int src = 0) {
    int n = graph.size();
    vi degrees(n), its(n), used(num_edges), result, stack = {src};
    degrees[src]++;
    
    while (!stack.empty()) {
        int x = stack.back(), y, e, &it = its[x], end = graph[x].size();
        if (it == end) {
            result.push_back(x);
            stack.pop_back();
            continue;
        }
        tie(y, e) = graph[x][it++];
        if (!used[e]) {
            degrees[x]--, degrees[y]++;
            used[e] = 1;
            stack.push_back(y);
        }
    }
    
    for (int x : degrees)
        if (x < 0 || result.size() != num_edges + 1)
            return {};
            
    return {result.rbegin(), result.rend()};
}

int edgeCount(int m) {
    if (m % 2 == 1)
        return m * (m - 1) / 2 + m;
    return ((m - 2) * (m - 2) + 2 * (m - 1)) / 2 + m;
}

void solve() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << "1 1\n";
        return;
    }

    int m = 1;
    while (edgeCount(m) < n - 1) ++m;

    vector<vector<pii>> graph(m);
    int edge = 0;

    auto addEdge = [&](int i, int j) {
        graph[i].emplace_back(j, edge);
        graph[j].emplace_back(i, edge);
        ++edge;
    };

    if (m % 2 == 1) {
        for (int i = 0; i < m; ++i)
            for (int j = i; j < m; ++j)
                addEdge(i, j);
    } else {
        for (int i = 0; i < m; ++i)
            addEdge(i, i);

        for (int i = 0; i < m; ++i)
            for (int j = i + 2; j < m; ++j)
                addEdge(i, j);
        for (int i = 0; i < m; i += 2)
            addEdge(i, i + 1);
    }

    auto path = eulerWalk(graph, edge);
    assert(path.size() >= n);
    path.resize(n);
    for (auto x : path)
        cout << primes[x] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve[0] = sieve[1] = true;
    for (int i = 2; i < X; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < X; j += i)
                sieve[j] = true;
        }
    }

    int t;
    cin >> t;
    while (t--) solve();
}
