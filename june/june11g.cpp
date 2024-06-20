#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll power(ll a,ll b)
{
    if(b==0)return 1;
    ll t=power(a,b/2);
    t=(1ll*t*t)%mod;
    if(b%2==1)t=(1ll*t*a)%mod;
    return t;
}
void solve()
{
    ll l,r,k;
    cin>>l>>r>>k;
    ll x=9/k+1;
    ll sr=power(x,r);
    ll sl=power(x,l);
    cout<<((sr-sl)%mod+mod)%mod<<'\n';
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        solve();
    }
    return 0;
}