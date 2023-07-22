#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int subtree_sum[N];
void dfs(int vertex, int par = -1){
    subtree_sum[vertex]+=vertex;
    for (int child : g[vertex]){
        if (child == par)
            continue;
        dfs(child, vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}

int main(){
    int n;
    cin >> n;
    int p = n - 1;

    while (p--){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int mx=-1;
    for(int i=1;i<=n;i++){
        int a=subtree_sum[i];
        int b=subtree_sum[1]-a;
        mx=max(mx,a*b);
    }
    cout<< mx;
}