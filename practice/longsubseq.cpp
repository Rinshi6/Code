#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int dp[N];
int func(int n){
    if(dp[n]!=-1) return dp[n];
    if(n<0) return 0;
    int len=1;
    for(int i=n;i>=0;i--){
        if(a[i]<a[n]) len= max(len,1+func(i));
    }
    return dp[n]=len;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<func(n-1);
}