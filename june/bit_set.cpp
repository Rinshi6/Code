#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,m;
    cin>>n>>m;
    if(m==1){
        cout<<n<<endl;
        return;
    }
    ll a=1,i=0;
    ll ans=0;
    while(true){
        if(n<a)break;
        ans+=a;
        i++;
        a*=2;

    }
    ll k=1;
    for(int j=0;j<i-m;j++){
        ans-=k;
        k*=2;
    }
    vector<ll> v;
    v.push_back(a-1);
    v.push_back(n);
    v.push_back(ans);
    sort(v.begin(),v.end());
    cout<<v[2];
}
int main(){
    solve();
}