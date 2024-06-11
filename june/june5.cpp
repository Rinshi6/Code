#include <bits/stdc++.h>
using namespace std;
int main() {
    long long t;
    cin >> t;
    long long ans=0;
    string s;
    s=to_string(t);
    if(s[0]=='9' || s[0]<='4')
    ans+=(s[0]-'0');
    else {
        ans+=('9'-s[0]);
    }
    for(int i=1;i<s.size();i++){
        ans=ans*10;
        if(s[i]<='4')ans+=(s[i]-'0');
        else ans+=('9'-s[i]);
    }  
    if(ans>0)  
    cout<<ans;
    else cout<<t;
    return 0;
}
