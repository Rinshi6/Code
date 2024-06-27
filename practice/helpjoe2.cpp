#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
        a[i]%=m;
    }
    int q;
    cin>>q;
    while(q--){
        int b;
        cin>>b;
        b%=m;
        int* p=upper_bound(a,a+n,m-b-1);
        if(p!=a){
            p--;
        }
        cout<<max((a[n-1]+b)%m, (*p+b)%m)<<endl;
    }
}