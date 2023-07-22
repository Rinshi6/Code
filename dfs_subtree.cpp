#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
int subtree[N];
int even_ct[N];
void dfs(int vertex){
    vis[vertex]=true;
    subtree[vertex]+=vertex;
    if(vertex%2==0) even_ct[vertex]++;
    for(int child: g[vertex]){
        if(vis[child])continue;
        dfs(child);
        subtree[vertex]+=subtree[child];
        even_ct[vertex]+=even_ct[child];
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    while(m--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<< subtree[i]<<" "<< even_ct[i]<<"\n";
    }
    return 0;
}