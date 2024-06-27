#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int c=0;
        int a;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(a==c+1)
            c=c+2;
            else c=c+1;
        }
        cout<<c<<endl;
    }
}