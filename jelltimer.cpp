#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        int c=0;
        vector<int> x;
        int y;
        int k=n;
        while(n--){
            cin>>y;
            x.push_back(y);
        }
        sort(x.begin(),x.end());
        int i=0;
        while(b){
            if(b==1 && i!=k){
                b=min(a,x[i]+b);
                i++;
            }
            b--;
            c++;
        }
        cout<<c<<endl;
    }
}