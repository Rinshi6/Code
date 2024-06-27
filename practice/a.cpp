#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    char s[4]={'v','i','k','a'};
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> a(n,vector<char> (m,'a'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[k]==a[j][i]){
                    k++;
                    break;
                }
            }
            if(k==4){
                break;
            }
        }
        if(k==4){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}