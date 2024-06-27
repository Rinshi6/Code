#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];
void dfs(int vertex, int par = -1)
{
    for (int child : g[vertex])
    {
        if (child == par)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}
int main()
{
    int n;
    cin >> n;
    int p = n - 1;

    while (p--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int mx = -1, mx_node = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mx < depth[i])
        {
            mx = depth[i];
            mx_node = i;
        }
        depth[i] = 0;
    }
    dfs(mx_node);
    mx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mx < depth[i])
        {
            mx = depth[i];
        }
    }
    cout << mx;
}