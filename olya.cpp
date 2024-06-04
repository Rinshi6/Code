#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int> &A, vector<int> &B) {
    return A[1] > B[1];
}
void print(vector<vector<int>> &c){
    int n=c.size();
    for(int i=0;i<n;i++){
        int m=c[i].size();
        for(int j=0;j<m;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin>> n;
        vector<vector<int>> a;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            vector<int> b;
            while(m--){
                int x;
                cin>>x;
                b.push_back(x);
                mn=min(x,mn);
            }
            sort(b.begin(),b.end());
            a.push_back(b);
        }
        print(a);
        sort(a.begin(),a.end(),comp);
        print(a);
        long long sum=0;
        for(int i=0;i<n-1;i++){
            sum+=(a[i][1]+0LL);
        }
        sum+=(mn+0LL);
        cout<<sum<<endl;
    }
}