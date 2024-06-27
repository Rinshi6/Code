#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int pa[N];
int size[N];
void make(int n){
    for(int i=0;i<=n;i++){
        pa[i]=i;
        size[i]=1;
    }
}
int find(int x){
    if(pa[x]==x) return x;
    else return pa[x]=find(pa[x]);
}

void uni(int x, int y){
    int a=pa[x],b=pa[y];
    if(a!=b){
        if(size[a]<size[b]) swap(a,b);
        pa[b]=a;
        size[a]+=size[b];
    } 
    
}
int main(){
    int n;
    cin>>n;
    make(n);
    vector<pair<int,int>> g;
    vector<pair<long long,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g.push_back({a,b});
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        edges.push_back({a,{0,i+1}});
    }
    int k[n];
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    for(int i=0;i<n;i++){
        int p=g[i].first,q=g[i].second;
        for(int j=i+1;j<n;j++){
            int a=g[j].first,b=g[j].second;
            long long cost=(abs(p-a)+abs(b-q))*1LL*(k[i]+k[j]);
            edges.push_back({cost,{i+1,j+1}});
        }
    }
    sort(edges.begin(),edges.end());
    long long total_cost=0;
    vector<int> power_stations;
    vector<pair<int,int>> connections;
    for(auto &edge : edges){
        int wt=edge.first;
        int x=edge.second.first;
        int y=edge.second.second;
        if(pa[x]==pa[y]) continue;
        uni(x,y);
        total_cost+=wt;
        if(x==0 || y==0){power_stations.push_back(max(x,y));}
        else connections.push_back({x,y});
    }
    cout<<total_cost<<endl;
    cout<<power_stations.size()<<endl;
    for(int power_station : power_stations){
        cout<<power_station<<" ";
    }
    cout<<endl<<connections.size()<<endl;
    for(auto connection : connections){
        cout<<connection.first<<" "<<connection.second<<endl;
    }
}