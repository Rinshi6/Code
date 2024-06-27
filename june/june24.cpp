#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    if(n==1){
        cout<<k<<endl;
        return;
    }
    ll p=k;
    ll a=1;
    vector<ll> ans;
    bool f=false;
    while(p){
        if(p&1) {
            ans.push_back(a);
        }
        p>>=1;        
        a*=2;        
    }
    cout<<ans.back()-1<<" "<<k+1-ans.back()<<" ";
    for(int i=2;i<n;i++)cout<<0<< " ";
    cout<<endl;
    
        
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}