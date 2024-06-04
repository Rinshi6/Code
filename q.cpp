#include <bits/stdc++.h> 
using namespace std;
const int N=10^9;
vector<pair<int,int>> moments={{0,1},{-1,0},{1,0},{0,-1}};
vector<vector<int>> vis(N,vector<int> (N,0));

void search(vector < vector < int >> & arr, int &n,int x, int y, vector<string> & ans,string s){
    if(x==n-1 && y==n-1){
        ans.push_back(s);

        return;

    }

    
    int i=0;string st="DLRU";
    for(auto m:  moments ){
        i++;
        int childx=m.first+x;
        int childy=m.second+y;
        cout<<childx<<" "<<childy;
        if(childx>=n || childy>=n || childx<0 || childy<0){cout<<"ss"<<st[i-1];continue;}
        if(vis[childx][childy] || arr[childx][childy]==0){cout<<vis[childx][childy]<<" "<< arr[childx][childy]<<" "<<st[i-1]<<endl; continue;}
    
        s+=st[i-1];
        cout<<s<<i<<endl;
        vis[x][y]=1;
        search(arr,n,childx,childy,ans,s);
        vis[x][y]=0;

    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    string s="";

    search(arr,n,0,0,ans,s);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<string> a=searchMaze(arr,n);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}