#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> g[N];
bool isvis[N];

bool dfs(int vertex,int par){
    isvis[vertex]= true;
    bool isloopexists=false;
    for(int child : g[vertex]){
        if(isvis[child] && child==par) continue;
        if(isvis[child]){
            return true;
        }
        isloopexists|=dfs(child,vertex);
    }
    return isloopexists ;
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
    bool loopp=false;
    for(int i=1;i<=n;i++){
        if(isvis[i]) continue;
        loopp=dfs(i,0);
        cout<<loopp;
    }
   // if(loopp) cout<<"true";
   // else cout<<"false";
    return 0;
}