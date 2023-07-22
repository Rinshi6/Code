#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N=1e3+7;;
const int INF=1e7+10;
int g[N][N];
bool vis[N][N];
int lev[N][N];

int n,m;
vector<pair<int,int>> movements={{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1},{-1,0},{1,0}};
bool isvalid(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}
void dfs(){
    int mx=0;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx<g[i][j])
            mx=g[i][j];
        }
    }
    queue<pair<int,int>> q ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx==g[i][j]){
                q.push({i,j});
                lev[i][j]=0;
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        auto v=q.front();
        int a=v.first, b=v.second;
        q.pop();
        for(auto movement : movements){
            int x=movement.first+a,y=movement.second+b;
            if(!isvalid(x,y)) continue;
            if(!vis[x][y]){
                q.push({x,y});
                lev[x][y]=1+lev[a][b];
                vis[x][y]=1;
                ans=max(ans,lev[x][y]);
            }
        }     
    }
    cout<<ans<<endl;
}
void reset(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=0;
            lev[i][j]=INF;
        }
    }
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    cin>>n>>m;
        reset(n,m);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>g[i][j];
	        }
	    }
        dfs();
	}
	return 0;
}
