#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> g[N];
bool isvertex[N];
void dfs(int vertex){
    //if(isvertex[vertex]) return;
    //take action after entering vertex
    isvertex[vertex]= true;
    cout<< vertex<< endl;
    for(int child : g[vertex]){
        if(isvertex[child]) continue;
        //take action before entering child
        cout<<"par "<<vertex << " child "<< child<<endl;
        dfs(child);
        //take action after exiting child
    }
    //take action before exiting vertex
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
        dfs(i);
    }
    dfs(1);
    return 0;
}