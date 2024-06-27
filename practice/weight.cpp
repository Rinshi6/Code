#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x,y;
        cin >>x>>y;
        int a,b;
        int f=0;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            if(a>=x && b>=y){
                f=1;
            }
        }
        if(f==0)
        cout<<x-1;
        else cout<<-1;
        cout<<endl;
    }
}