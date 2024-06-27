#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<pair<int,int>> point_st;
    vector<pair<int,int>> point(n);
    for(int i=0;i<n;i++){
        cin>>point[i].first>>point[i].second;l
        point_st.insert(point[i]);
    }
    int ar_mn=INT_MAX,ar_mx=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto p1=point[i];
            auto p2=point[j];
            int x1=p1.first,x2=p2.first;
            if(x1==x2) continue;
            int y1=p1.second,y2=p2.second;
            if(y1==y2) continue;
            if(point_st.count({x1,y2}) && point_st.count({x2,y1}))  {
                int ar=abs(x1-x2)*abs(y1-y2);
                if(ar_mx<ar) ar_mx=ar;
                if(ar_mn>ar) ar_mn=ar;
            }
        }
    }
    cout<<ar_mx-ar_mn;
}