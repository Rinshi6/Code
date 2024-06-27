#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    int c[n],a[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    a[0]=c[0];
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+c[i];
    }
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int out;
        out=a[r-1]-a[l-2];
        cout<<out;
    }
}