#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> d(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }
    int cn;
    cin>>cn;
    for(int k=0;k<cn;k++){
        int a,b,p;
        cin>>a>>b>>p;
        a--;
        b--;
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],d[i][a]+p+d[b][j]);
                d[i][j]=min(d[i][j],d[i][b]+p+d[a][j]);
                sum+=(d[i][j]+0LL);
            }
        }
        cout<<sum/2<<" "; 
    }
}