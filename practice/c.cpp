#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        vector<pair<int,int>> b;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(b.begin(),b.end());
        // for(int k=0;k<50;k++){
            int cn=0;
            int i=0;
            for(;i<n;i++){
                while(a[i]<=a[i+1]){
                i++;
                if(i>n-2)break;
                }
                if(i>n-2)break;
                while(a[i]>a[i+1]){
                    a[i+1]=a[i]+a[i+1];
                    b.push_back({i,i+1});
                    cn++;
                }
            }
            i=0;
        cout<<cn<<endl;
        for(int i=0;i<b.size();i++){
            cout<<b[i].first<<" "<<b[i].second<<endl;
        }

    }
}