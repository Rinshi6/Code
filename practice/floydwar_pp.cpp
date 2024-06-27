#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
        int wt;
        cin>>wt;
        a[x][y]=wt;
        }
    }
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    int s[n];
    for(int k=n-1;k>=0;k--){
        int shot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][p[k]]+a[p[k]][j]);
            }
        }
        for(int i=0;i<n-k;i++){
            for(int j=0;j<n-k;j++){
                shot+=a[p[n-1-i]][p[n-1-j]];
            }
        }
        s[k]=shot;
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
}