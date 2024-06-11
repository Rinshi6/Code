#include<bits/stdc++.h>
using namespace std;
long long mn[20];
long long mx[20];
void solve(){
    long long n;
    cin>>n;
    int cn=0;
    long long k=n;
    while(k){
        k=k/10;
        cn++;
    }
    cn--;
    cout<<cn<<" "<<mn[cn]<<" "<<mx[cn]<<" ";
    if(n>=mn[cn] && n<=mx[cn]){
        
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    long long i=5,j=9;
    mn[0]=0;
    mx[0]=0;
    for(int i=1;i<19;i++){
        mn[i]=mn[i-1]*10+5;
        mx[i]=mx[i-1]*10+9;
    }
    for(int i=1;i<19;i++){
        mn[i]=mn[i]*2;
        mx[i]=mx[i]*2;
    }
    while(t--){
        solve();
    }
}