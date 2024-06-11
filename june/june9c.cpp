#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
void solve(){
    int n;
    cin>>n;
    unordered_map<long long,long long> mp;
    mp[0]=1;
    long long x;
    for(int i=0;i<n;i++){
        cin>>x;
        unordered_map<long long,long long> new_mp;

        for(auto&  a :mp){
            new_mp[x+a.first]+=a.second;
            new_mp[abs(x+a.first)]+=a.second;
        }
        vector<pair<long long,long long>> v(new_mp.begin(),new_mp.end());
        mp.clear();
        mp[v[0].first]=v[0].second;
        mp[v[v.size()-1].first]=v[v.size()-1].second;
    }
    long long ans;
    for(auto&  a :mp){
        ans=a.second;
    }
    cout<<ans%mod<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}