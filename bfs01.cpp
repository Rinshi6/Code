#include <bits/stdc++.h>
using namespace std;
const int N=1e7+7;
const int INF=1e9+10;
vector<pair<int,int>> g[N];
vector<int> lev(N,INF);
int n,m;
int bfs( ){
    deque<int> q;
    q.push_back(1);
    lev[1]=0;
    while(!q.empty()){
        int ce=q.front();
        q.pop_front();
        for(auto child : g[ce]){
            int child_v=child.first;
            int wt=child.second;
            if(lev[ce]+wt<lev[child_v]){
                lev[child_v]=wt+lev[ce];
                if(wt==1) q.push_back(child_v);
                else q.push_front(child_v);
            }
        }
    }
    return lev[m]==INF ? -1: lev[m];
}

int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(x==y) continue;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    cout<<bfs();
    return 0;
}