    #include <bits/stdc++.h>
    using namespace std;
    
    int vis[210];
    vector<int> v[210];
    void dfs(int i){
        vis[i]=1;
        for(int ele: v[i]){
            if(vis[i]) continue;
            dfs(ele);
        }
        return;
    }
    void findCircleNum(vector<vector<int>>& connected) {
        int n=connected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(connected[i][j]==1 && i!=j){
                v[i].push_back(j);
                v[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            c+=1;
            dfs(i);
            cout<<i<<"i ";
        }
        cout<< c;
    }
    int main(){
        int n;
        cin>>n;
        vector<vector<int>> cn(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>cn[i][j];
            }
        }
        findCircleNum(cn);

    }