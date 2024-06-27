#include <bits/stdc++.h>
using namespace std;
long long dp[105][100005];
int w[105],v[105];
long long func(int ind,int wt){
    if(wt==0) return 0;
    if(ind<0)return 0;
    if(dp[ind][wt]!=-1) return dp[ind][wt];
    long long mx_val=func(ind-1,wt);
    if(wt-w[ind]>=0)
    mx_val=max(mx_val,func(ind-1,wt-w[ind]))+v[ind];
    return dp[ind][wt]=mx_val;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,wt;
    cin>>n>>wt;
    int i=0;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<func(n-1,wt);
}