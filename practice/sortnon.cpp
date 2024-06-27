#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int c=0;
        int so=2;
        bool flag=1;
        for(int i=0;i<n;i++){
            if(s[i]=='+'){
                c++;
            }
            else if(s[i]=='-'){
                if(c>0) c--;
                else {
                    flag=0;
                    //cout<<"i "<<i<<" c "<<c<<endl;
                    break;
                }
            }
            else if(s[i]=='0'){
                if(c<2){
                    flag=0;
                    //cout<<"i "<<i<<" c "<<c<<endl;
                    break;
                }
                else{
                    so=0;
                }
            }
            else{
                if(c<2){
                    so=1;
                }
                else if(so==0){
                    flag=0;
                    //cout<<"i "<<i<<" c "<<c<<endl;
                    break;
                }
                else  if(so==2){
                    so=1;
                }
            }
            if(c<2){
                so=1;
            }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}