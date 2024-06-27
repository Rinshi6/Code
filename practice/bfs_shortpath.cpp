#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
int level[8][8];
int vis[8][8];
vector<pair<int,int>> moments={
{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1,},{-2,-1}
};
int getx(string s){
	return s[0]-'a';
}
int gety(string s){
	return s[1]-'1';
}
bool isvalid(int x, int y){
    return x>=0 && y>=0 && x<8 && y<8;
}
int bfs(string source,string dst){
    queue<pair<int,int>> q;
   	int sourcex=getx(source);
   	int sourcey=gety(source);
   	int desx=getx(dst);
   	int desy=gety(dst);
    q.push({sourcex,sourcey});
    vis[sourcex][sourcey]=1;
    level[sourcex][sourcey]=0;
    while(!q.empty()){
        pair<int,int> p=q.front();
        int a=p.first, b=p.second;
        q.pop();
        for(auto moment : moments){
            int x=moment.first+a;
            int y=moment.second+b;
            if(!isvalid(x,y)) continue;
            if(!vis[x][y]){
                q.push({x,y});
                level[x][y]=level[a][b]+1;
                vis[x][y]=1;
            }
 
        }
        if(level[desx][desy]!=INF) break;
    }   
    return level[desx][desy];
}
void reset( ){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            vis[i][j]=0;
            level[i][j]=INF;
        }
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        reset();
        string s1,s2;
        cin>> s1>>s2;
        cout<<bfs(s1,s2);
    }
}