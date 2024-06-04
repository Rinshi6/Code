#include <bits/stdc++.h>
using namespace std;

int dp[47];
    int solve(int &n,int k){
        if(dp[k]!=-1)return dp[k];
        if(k<=0){
            if(k==0)
            return 1;
            return 0;
        }
        
        return dp[k]=dp[k-1]+dp[k-2];
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        return solve(n,n);
    }
    int main(){

        cout<<climbStairs(4);
        for(int i=0;i<7;i++){
            cout<<" "<<dp[i]<<" ";
        }
    }