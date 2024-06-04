#include<bits/stdc++.h>
using namespace std;
const int INF=10^9;
const int N=510;
long long v[N][N];
int main(){
    
        int n;
        cin>>n;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>v[i][j];
            }
        }
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>> a[i];
        reverse(a.begin(),a.end());
        vector<long long >sum;
        for(int k=0;k<n;k++){
            int kv=a[k];
            for(int i=1;i<=n;i++){
                
                for(int j=1;j<=n;j++){
                    long long dis=v[i][kv]+v[kv][j];
                    v[i][j]=min(v[i][j],dis);
                    
                }
            }
            long long s=0;
            for(int i=0;i<=k;i++){
                for(int j=0;j<=k;j++){
                    s+=v[a[i]][a[j]];
                }
            }
            sum.push_back(s);
        }
        
        
        reverse(sum.begin(),sum.end());
        for(int i=0;i<n;i++)cout<<sum[i]<<" ";
        cout<<endl;
    }
