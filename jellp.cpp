#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n%m==0) cout<<0<<endl;
        else{
        int k=(m/(n%m));
        int p=1;
        while(p<k){
            p=p*2;
            if(p==k) break;
        }
        if(p==k){
            cout<<"k "<<k<<p;
            cout<<(p-1)*(n-((n/m)*m))<<endl;
        }
        else{ 
        cout<<-1<<endl;
        }
        }
    }
}