#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,k;
    cin>>n>>k;
    if(k&1){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    int sum=0;
    int l=0,r=n-1;
    while(l<r){
        if(!k)break;
        int t=abs(ans[l]-ans[r])*2;
        if(k>=t){
            swap(ans[l++],ans[r--]);
            k-=t;
        }
        
        
        else r--;
    }
    if(k){
        cout<<"NO\n";
        return;
    }
    cout<<"Yes"<<endl;
    for(auto & x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
