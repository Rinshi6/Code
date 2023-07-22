#include <bits/stdc++.h>
using namespace std;
const int N=50;
int h[N];
int dp[N];
int n,k;
int func(int j){
    if(j==0)    return 0;
    if(dp[j]!=-1) return dp[j];
    int cost=INT_MAX;
    for(int i=1;i<=k;i++){
        if(j>i-1) 
            cost =min(cost, func(j-i)+abs(h[j]-h[j-i]));
    }
    return dp[j]=cost;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<func(n-1);
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N=50;
int h[N];
int dp[N];

int func(int j){
    if(dp[j]!=-1) return dp[j];
    //int cost=INT_MAX;
    if(j==0)    return 0;
    dp[j] =(func(j-1)+abs(h[j]-h[j-1])); 
    if(j>1) dp[j] =min(dp[j], func(j-2)+abs(h[j]-h[j-2]));
    return dp[j];
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<func(n-1);
}


#include <bits/stdc++.h>
using namespace std;
const int N=50;
int h[N];
int dp[N];
int func(int j){
    if(dp[j]!=-1) return dp[j];
    if(j==0)    return 0;
    if(j<2) return dp[j]=func(j-1)+abs(h[j]-h[j-1]);
    else return dp[j]=min((func(j-2)+abs(h[j]-h[j-2])),(func(j-1)+abs(h[j]-h[j-1]))); 
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cout<<func(n-1);
}*/