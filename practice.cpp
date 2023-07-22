#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int i=0; i<n;i++){
        long long b;
        cin>>b;
        int p=b%m;
        a.push_back(p);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        long long b;
        cin>>b;
        int mx=0;
        for(int j=0;j<n;j++){
            int c=(a[j]+(b%m))%m;
            if(mx<c) mx=c;
        }
        cout<<mx<<endl;
    }
}