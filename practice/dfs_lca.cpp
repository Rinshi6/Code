#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];
int pa[N];
void dfs(int vertex, int par = -1)
{
    pa[vertex]=par;
    for (int child : g[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
    }
}
vector<int> path(int x){
    vector<int> ans;
    while(x!=-1){
        ans.push_back(pa[x]);
        x=pa[x];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    int x,y;
    cin>>x>>y;
    vector<int> p1=path(x),p2=path(y);
    int lca=-1;
    int sz=(p1.size()>p2.size() ? p2.size() : p1.size());
    for(int i=0;i<sz;i++){
        if(p1[i]==p2[i]){
            lca=p1[i];
        }
        else{
            break;
        }
    }
    cout<<lca;
}