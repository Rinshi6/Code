#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>> s;
        char a='<',b='>';
        int flag=0;
        int p=0,q=0;
        int ans=0;
        if(s[0]=='<'){p++;flag=0;}
        else {q++;flag=1;}
        for(int i=1;i<n;i++){
            if(s[i]=='<'){
                if(flag){ans=max(ans,q);p=1;flag=0;}
                else{p++;}
            }
            else{
                if(flag==0){ans=max(ans,p);q=1;flag=1;}
                else{q++;}
            }
        }
        ans=max(ans,max(p,q));
        cout<<ans+1<<endl;
    }
}
