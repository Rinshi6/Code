#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> g[N];
bool isvertex[N];
vector<int> current_cc;
vector<vector<int>> cc;
void dfs(int vertex){
    if(isvertex[vertex]) return;
    isvertex[vertex]= true;
    current_cc.push_back(vertex);
    cout<<vertex<<" ";
    for(int child : g[vertex]){
        dfs(child);
    }
    return ;
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
    for(int i=1;i<=n;i++){
        if(isvertex[i]) continue;
        current_cc.clear();
        dfs(i);
        cout<<endl;
        cc.push_back(current_cc);
    }
    return 0;
}