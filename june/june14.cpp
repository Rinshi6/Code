#include <bits/stdc++.h>
using namespace std;

char solve() {
    string s;
    int pos;
    cin>>s>>pos;
    string r;
    int n=s.size();
    while(n--){
        r+=s;
        int mi=0;
        char c=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]>=c){
                c=s[i];
                mi=i;
            }
        }
        s=s.substr(0,mi)+s.substr(mi+1,n-mi);
    }
    cout<<r[pos-1];
}

int main() {
    int t;
    string ans;
    cin >> t;
    while (t--) {
       ans+= solve();
    }
    cout<<ans;
    return 0;
}
