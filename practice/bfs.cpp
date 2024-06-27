#include <bits/stdc++.h>
using namespace std;
const int N=1e7+7;
vector<int> g[N];
int level[N];
bool vis[N];
void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=true;
    while(!q.empty()){
        int ce=q.front();
        q.pop();
        cout<<ce<<" ";
        for(int child : g[ce]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                level[child]=level[ce]+1;
            }
        }
    }
    cout<<endl;
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
    for(int i=1;i<=n;i++){
        cout<<level[i]<<"\n";
    }
}