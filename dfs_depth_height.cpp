#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> g[N];
vector<int> depth(N,0);
vector<int> height(N,0);

void dfs(int vertex,int par=-1){
    for(int child : g[vertex]){
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[child]+1,height[vertex]);
    }
    return ;
}
int main(){
    int n,m;
    cin>>n; 
    m=n-1;
    while(m--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<< height[i]<<" "<<depth[i]<<endl;
    }
    return 0;
}