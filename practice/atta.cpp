#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a,b;
        vector<vector<int>> v;
        vector<bool> vis(50,0);
        vector<int> un;
        vector<int> cn(50,0);
        for(int i=0;i<n;i++){
            vector<int> c;
            cin>>a;
            if(vis[a]==0){
                vis[a]=1;
                un.push_back(a);
                cn[i]++;
            }
            c.push_back(a);
            while(a--){
                cin>>b;
                c.push_back(b);
                if(vis[b]==0){
                    vis[b]=1;
                    un.push_back(b);
                    cn[i]++;
                }
            }
            v.push_back(c);
        }
        int mi=51;
        for(int i=0;i<n;i++){
            if(cn[i]<mi && cn[i]!=0){
                mi=cn[i];
            }
        }
        cout<<(un.size()-mi)<<endl;
    }
}