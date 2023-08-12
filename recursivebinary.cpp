#include <bits/stdc++.h>
using namespace std;
void binary(int s, int e, vector<int>& v, int val){
    if(s>e){
        cout<<"not found";
        return;
    }
    int m=(s+e)/2;
    if(v[m]==val){
        cout<<m<<" found";
    }
    else if(v[m]>val) binary(s,m-1,v,val);
    else binary(m+1,e,v,val);
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int val;
    cin>>val;
    binary(0,n-1,v,val);
}