#include <bits/stdc++.h>
using namespace std;

const int N=1e5+9;
int parent[N];
int size[N];
 
void make(int v){
    parent[v]=v;
    size[v]=1;
}
int find(int v){
    if(parent[v]==v) return v;
    else return parent[v]=find(parent[v]);
}

void uni(int x, int y){
    int a=parent[x];
    int b=parent[y];
    if(a!=b){
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int wt,x,y;
        cin>>wt>>x>>y;
        edges.push_back({wt,{x,y}});
    }
    for(int i=1;i<=n;i++){
        make(i);
    }
    sort(edges.begin(),edges.end());
    int total_cost=0;
    for(auto &edge : edges){
        int wt=edge.first;
        int x=edge.second.first;
        int y=edge.second.second;
        if(find(x)==find(y)) continue;
        uni(x,y);
        cout<<x<<" "<<y;
        total_cost+=wt;
    }
    cout<<total_cost;
}