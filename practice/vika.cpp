#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> p(n,{0,0});
        for(int i=0;i<n;i++){
            cin>>p[i].first;
            p[i].second=i;
        }
        sort(p.begin(),p.end());
        int cur=-1,dis,times,dis_p=INT_MAX;
        for(int i=1;i<=k;i++){
            int dis_c=p[cur].second+1,times=1;
            while(p[cur].first==i && cur+1<n){
                cur++;
                if(p[cur+1].first==i){
                    int dif=p[cur+1].second-p[cur].second;
                    if(dif==dis_c) times++;
                    else if(dif>dis_c){
                        dis_c=dif;
                        times=1;
                    }
                }
                else{
                    break;
                }
            }
            cur++;
            if(times==1){
                dis_c/=2;
            }
            int dif=n-p[cur-1].second;
            if(dif==dis_c) times++;
            else if(dif>dis_c){
                dis_c=dif;
                times=1;
            }
            if(dis_c<dis_p){
                dis_p=dis_c;
            }
        }
        if(dis_p>0)
        cout<<dis_p-1<<endl;
        else
        cout<<k/3<<endl;
    }
}