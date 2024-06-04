#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int mj=0;
        int mg=0;
        int sum=0;
        int nj=INT_MAX;
        int ng=INT_MAX;
        int a;
        while(n--){
            cin>>a;
            sum+=a;
            if(a>mj){
                mj=a;
            }
            if(a<nj){
                nj=a;
            }
        }
        while(m--){
            cin>>a;
            if(a>mg){
                mg=a;
            }
            if(a<ng){
                ng=a;
            }
        }
        if(k%2){
            if(mg>nj){
                sum=sum+mg-nj;
            }
        }
        else{
            if(mj>ng){
                sum=sum-mj+ng;
            }
        }
        cout<<sum<<endl;
    }   
}