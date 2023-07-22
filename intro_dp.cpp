#include <bits/stdc++.h>
using namespace std;
const int N=100;
long long dp[N];

long long fibo(int n){
    if(dp[n]!=-1 ) return dp[n];
    else return dp[n]=fibo(n-1)+fibo(n-2);
}
int main(){
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    int n;
    cin >> n;
    cout<<fibo(n)<<" ";
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
}