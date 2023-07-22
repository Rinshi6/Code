#include <bits/stdc++.h>
using namespace std;
long long  dp[105][100005];
int w[105],v[105];
long long func(int ind,int vl){
    if(vl==0) return 0;
    if(ind<0) return 1e15;
    if(dp[ind][vl] != -1) return dp[ind][vl];
    long long mn_wt=func(ind-1,vl);
    if(vl-v[ind]>=0)
    mn_wt=min(mn_wt,func(ind-1,vl-v[ind])+w[ind]);
    return dp[ind][vl]=mn_wt;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,wt;
    cin>>n>>wt;
    int i=0;
    while(i!=n){
        cin>>w[i]>>v[i];
        i++;
    }
    for(int i=1e5;i>=0;i--){
        if(func(n-1 ,i)<=wt) {
            cout<< i<<endl;;
            break;
        }
    }
}