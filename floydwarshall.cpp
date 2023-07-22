#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][n];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) a[i][j]=0;
            else a[i][j]=INF;
        }
    }
    while(m--){
        int x,y,wt;
        cin>>x>>y>>wt;
        a[x][y]=wt;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}