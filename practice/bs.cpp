#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int c=0;
        for(int i=1;i<s.size();i++){
            if(!((s[i]==0 && s[i-1]==1) || (s[i]==1 && s[i-1]==0))){
                c=c+2;
                s[i]=s[i-1];
            }

        }
    }
}