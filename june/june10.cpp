#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    vector<int> d;
    while(n){
        d.push_back(n%10);
        n/=10;
    }
    if(d.back()!=1){
        cout<<"no\n";
        return;
    }
    for(int i=d.size()-1;i>0;i--){
        d[i]-=1;
        d[i-1]+=10;
    }
    d.pop_back();
    bool ok=(*min_element(d.begin(),d.end())>=10 && *max_element(d.begin(),d.end())<=18);
    if(ok){
        cout<<"Yes\n";
    }
    else cout<<"no\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}