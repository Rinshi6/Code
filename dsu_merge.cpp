#include <bits/stdc++.h>
using namespace std;

const int N=1e5+9;
int parent[N];
int size[N];
multiset<int> s;

void make(int v){
    parent[v]=v;
    size[v]=1;
    s.insert(1);
}

int find(int v){
    if(parent[v]==v) return v;
    else return parent[v]=find(parent[v]);
}

void mer(int a, int b){
    s.erase(s.find(size[a]));
    s.erase(s.find(size[b]));
    s.insert(size[a]+size[b]);
}

void uni(int x, int y){
    int a=parent[x];
    int b=parent[y];
    if(a!=b){
        if(size[a]<size[b])
            swap(a,b);
        mer(a,b);
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
        uni(u,v);
        if(s.size()==1){
            cout<<0<<endl;
        }
        else{
            int mx=*(s.begin());
            int mn=*(--s.end());
            cout<<mx-mn<<endl;
        }
    }

}