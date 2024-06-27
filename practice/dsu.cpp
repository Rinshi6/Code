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
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(m--){
        int u,v;
        cin>>u>>v;
        uni (u,v);
    }
    int connected_ct=0;
    for(int i=1;i<=n;i++){
        if(parent[i]==i)connected_ct+=1;
    }
    cout<<connected_ct;

}