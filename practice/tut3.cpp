#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        int a=0,b=0;
        cin>> n;
        for(int i=0;i<n.size();i++){
            if(n[i]=='0')a++;
            else b++;
        }
        if(a==b) cout<<0<<endl;
        else {
            a=(a>b ? b:a);
            b=a;
            
            int i=0;
            for(i=0;i<n.size();i++){
                if(n[i]=='0'){
                    if(b)b--;
                else break;}
                else {
                    if(a){
                        a--;
                    }
                else break;
                }
            }
            cout<<n.size()-i<<endl;
        }
    }
}