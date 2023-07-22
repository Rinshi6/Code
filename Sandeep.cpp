#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,pair<int ,int >> p1, pair<int,pair<int ,int >> p2){
    long long s1=p1.second.first+p1.second.second;
    long long s2=p2.second.first+p2.second.second;
    if(s1!=s2) return s1<s2;
    return p1.second.first<p2.second.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,pair<int ,int >>> sum(n);
        for(int i=0;i<n;i++){
            cin>>sum[i].second.first>>sum[i].second.second;
            sum[i].first=i;
        }
        sort(sum.begin(),sum.end(),cmp);
        vector<int> data(n);
        for(int i=0;i<n;i++){
            data[sum[i].first]=i;
        }
        for(auto ele:data){
            cout<<ele<<" ";
        }
    }
}