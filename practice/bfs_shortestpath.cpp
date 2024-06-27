#include <bits/stdc++.h>
using namespace std;
const int N=1e7+7;
vector<int> g[N];
//int level[N];
bool vis[N];
int pa[N];
void bfs(int source,int par=-1){
    queue<int> q;
    q.push(source);
    vis[source]=true;
    pa[source]=par;
    while(!q.empty()){
        int ce=q.front();
        q.pop();
        //cout<<ce<<" ";
        for(int child : g[ce]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                //level[child]=level[ce]+1;
                pa[child]=ce;
            }
        }
    }
    cout<<endl;
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

int main(){
    int n;
    cin>>n;
    int p=n-1;
    while(p--){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    int x;
    cin>>x;
    vector<int> path_x=path(x);
    for(int i=1;i<path_x.size();i++){
        cout<<path_x[i]<<" ";
    }
}