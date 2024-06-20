#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    long long x;
    long long mn1=1e9+5,mn2=1e9+5,sum1=0,sum2=0;
    for(int j=0;j<n;j++){
        cin>>x;
        mn1=min(x,mn1);
        sum1+=x;
    }
    for(int j=0;j<n;j++){
        cin>>x;
        mn2=min(x,mn2);
        sum2+=x;
    }
    sum1+=(n*mn2);
    sum2+=(n*mn1);
    if(sum1<sum2)cout<<sum1<<endl;
    else cout<<sum2<<endl;
    
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}