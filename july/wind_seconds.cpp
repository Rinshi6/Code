#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,k;
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>k;
        ans=max(ans,k+i);
    }    
    cout<<ans<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}