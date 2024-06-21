#include <bits/stdc++.h>
using namespace std;
long long dp[101][1000000005];
long long solve(int& n, int w, vector<long long>& a, int i,vector<long long>& v){
  if(i==n)return 0;
  if(dp[i][w]!=-1)return dp[i][w];
  long long ans=0;
  if(w-a[i]>=0)
    ans=solve(n,w-a[i],a,i+1,v)+v[i];
  ans=max(ans,solve(n,w,a,i+1,v));
  return dp[i][w]=ans;
}
int main(){
  memset(dp,-1,sizeof(dp));
  int n,w;
  cin>>n>>w;
  vector<long long> a(n),v(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>v[i];
  }
  
  cout<<"sol"<<solve(n,w,a,0,v);
}